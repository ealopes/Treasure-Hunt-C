/*
 * production.c
 *
 *  Created on: Sep 11, 2019
 *      Author: Eric Lopes
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "production.h"
#include "House.h"

void production(int argc, char* argv[]){
	if (argc>1){
		char* graphLoc = argv[1];
		FILE* fp = fopen(graphLoc,"r");
		char dummy[0];
		char* str;
		int nRows = strtol(fgets(dummy,100,fp),&str,10);
		fclose(fp);

		int* layout = CreateHouse(Make2DArray(nRows));
		Room* rooms = CreateRooms();
		int* TotalRooms = (int*)malloc(sizeof(int));
		int* TotalTreasure = (int*)malloc(sizeof(int));
		SetTotalRoomsTreasure(argc,argv,TotalRooms,TotalTreasure);
		int* roomsVisited = (int*)malloc(sizeof(int));
		*roomsVisited = 0;
		int* currentTreasure = (int*)malloc(sizeof(int));
		*currentTreasure = 0;
		int currentRoom = 0;
		bool breakcondition = true;
		if ((*TotalRooms<=0) || (*TotalTreasure<=0)){
			printf("Invalid input parameters. No search conducted.\n");
		} else {

			char d = "0";
			int chosenRoom1 = strtol(&d,&str,10);
			currentRoom=ChooseRoom(currentRoom,chosenRoom1,roomsVisited,currentTreasure,rooms,layout);
			*roomsVisited = 0;
			*currentTreasure = 0;
			(rooms)->visited=false;

			while (breakcondition){
				PrintRoomsTreasure(currentRoom,currentTreasure);
				int* roomChoices = DisplayRoomChoices(currentRoom, layout);
				int chosenRoom;
				fflush(stdin);
				printf("Choose a room: ");
				fflush(stdout);
				char a = getchar();
				chosenRoom = strtol(&a,&str,10);
				currentRoom = ChooseRoom(currentRoom,chosenRoom,roomsVisited,currentTreasure,rooms,layout);
				breakcondition = !TooManyRoomsTreasure(roomsVisited,currentTreasure,TotalRooms,TotalTreasure);
			}
			printf("You left the house with %d treasure.",*currentTreasure);
		}
	}else{
		printf("Please specify file location of graph.\n");
	}
}
