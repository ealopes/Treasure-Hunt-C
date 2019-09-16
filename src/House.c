/*
 * House.c
 *
 *  Created on: Sep 11, 2019
 *      Author: Eric Lopes
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "House.h"

int* Make2DArray(int nRows){
	int* Array_P = (int*)malloc(nRows*nRows*sizeof(int));
		for(int i=0;i<nRows;i++){
			for(int j=0;j<nRows;j++){
				*(Array_P+i*nRows+j)=0;
			}
		}

	return Array_P;
}

int* CreateHouse(int* blankhouse){
	FILE* fp = fopen("houseGraph.txt","r");
	char ch;
	char dummy[0];
	char* str;
	int nRows = strtol(fgets(dummy,100,fp),&str,10);
	int col = 0;

	for(int i = 0;i<nRows;i++)
	{
		while ((ch = fgetc(fp)) != '\n'){
			if (ch != ' ') {
				*(blankhouse+i*nRows+col)=atoi(&ch);
				col=col+1;
			}
		}
		col=0;
	}
	fclose(fp);
	return blankhouse;
}

void SetTotalRoomsTreasure(int argc, char* argv[], int* TotalRooms, int* TotalTreasure){
	if (argc > 2) {
		char* str;
		*TotalRooms = strtol(argv[2],&str,10);
		if (argc > 3) {
			char* str;
			*TotalTreasure = strtol(argv[3],&str,10);
			printf("Total rooms is set to %d.\n",*TotalRooms);
			printf("Total treasure is set to %d\n",*TotalTreasure);
		} else{
			fflush(stdin);
			printf("Input total treasure: ");
			fflush(stdout);
			char a[3];
			char* str;
			scanf("%3s",a);
			*TotalTreasure=strtol(a,&str,10);
			printf("Total rooms is set to %d.\n",*TotalRooms);
			printf("Total treasure is set to %d\n",*TotalTreasure);
		}
	} else {
		fflush(stdin);
		printf("Input total rooms: ");
		fflush(stdout);
		char a[3];
		char* str;
		scanf("%s",a);
		*TotalRooms=strtol(a,&str,10);
		fflush(stdin);
		printf("Input total treasure: ");
		fflush(stdout);
		char b[3];
		scanf("%s",b);
		*TotalTreasure=strtol(b,&str,10);
		printf("Total rooms is set to %d.\n",*TotalRooms);
		printf("Total treasure is set to %d\n",*TotalTreasure);
	}

}

int* DisplayRoomChoices(int currentroom, int* layout){
	FILE* fp = fopen("houseGraph.txt","r");
	char dummy[0];
	char* str;
	int nRows = strtol(fgets(dummy,100,fp),&str,10);
	fclose(fp);
	int* ConnectedRooms=(int*)malloc(nRows*sizeof(int));
	printf("You're currently connected to room(s):");
	for(int i=0;i<nRows;i++){
		*(ConnectedRooms+i)=0;
		if(*(layout+currentroom*nRows+i)==1){
			printf(" %d",i);
			*(ConnectedRooms+i)=1;
		}
	}
	printf(".\n");
	return ConnectedRooms;
}

int ChooseRoom(int current, int chosen, int* currentRooms, int* currentTreasure, Room* rooms, int* layout){
	if(RoomIsConnected(current,chosen,layout)){
		*currentTreasure=CollectTreasure((rooms+chosen),*currentTreasure);
		*currentRooms=*(currentRooms)+1;
		return chosen;
	} else {
		return current;
	}
}

bool TooManyRoomsTreasure(int* room, int* treasure, int* maxRooms, int* maxTreasure){
	if (*room >= *maxRooms){
		printf("You reached the max number of rooms and leave.\n");
	}
	if (*treasure >= *maxTreasure){
		printf("You maxed out on treasure and leave.\n");
	}
	return ((*room >= *maxRooms) || (*treasure >= *maxTreasure));
}

void PrintRoomsTreasure(int room, int* treasure){
	printf("Currently in room %d with %d treasure.\n",room,*treasure);
}
