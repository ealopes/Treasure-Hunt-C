/*
 * Room.c
 *
 *  Created on: Sep 11, 2019
 *      Author: Eric Lopes
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Room.h"

Room* CreateRooms(){
	char dummy[100];
	FILE* fp = fopen("houseGraph.txt","r");
	char* str;
	int nRows = strtol(fgets(dummy,100,fp),&str,10);
	Room* TreasureList = (Room*)malloc(nRows*sizeof(Room));
	for (int i = 0;i<nRows;i++){
		fgets(dummy,100,fp);
	}
	for (int i = 0; i<nRows; i++){
		char* str;
		(TreasureList+i)->treasure=strtol(fgets(dummy,100,fp),&str,10);
		(TreasureList+i)->visited=false;
	}
	fclose(fp);
	return TreasureList;
}

bool RoomIsConnected(int current, int chosen, int* layout){
	FILE* fp = fopen("houseGraph.txt","r");
	char dummy[0];
	char* str;
	int nRows = strtol(fgets(dummy,100,fp),&str,10);
	fclose(fp);

	if(*(layout+nRows*current+chosen)==1){
		return true;
	}else{
		printf("Not a valid room choice.\n");
		return false;
	}
}

int CollectTreasure(Room* room, int currentTreasure){
	if ((room->visited)==false){
		room->visited=true;
		currentTreasure = currentTreasure+room->treasure;
	}
	return currentTreasure;
}
