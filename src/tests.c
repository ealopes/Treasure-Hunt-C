/*
 * tests.c
 *
 *  Created on: Sep 11, 2019
 *      Author: Eric Lopes
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests.h"
#include "House.h"
#include "Room.h"

bool tests(){
	bool ok1 = testMake2DArray();
	bool ok2 = testCreateHouse();
	bool ok3 = testCreateRooms();
	bool ok4 = testSetTotalRoomsTreasure();
	bool ok5 = testDisplayRoomChoices();
	bool ok6 = testCollectTreasure();
	bool ok7 = testChooseRoom();
	bool ok8 = testTooManyRoomsTreasure();
	bool ok9 = testPrintRoomsTreasure();
	return ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;
}

bool testMake2DArray(){
	bool ok = false;
	FILE* fp = fopen("houseGraph.txt","r");
	int nRows;
	char dummy[0];
	nRows = atoi(fgets(dummy,10,fp));
	fclose(fp);
	int* testArray = Make2DArray(nRows);
	for(int i=0;i<nRows;i++){
		printf("|");
			for(int j=0;j<nRows;j++){
				printf("%d",*(testArray+i*nRows+j));
			}
		printf("|\n");
		}
	fflush(stdin);
	printf("Is this an array of all zeroes?(y/n): ");
	fflush(stdout);
	char a = getchar();
	if (a == 'y'){
		ok = true;
		}

	return ok;
}

bool testCreateHouse(){
	bool ok = false;
	FILE* fp = fopen("houseGraph.txt","r");
	int nRows;
	char dummy[0];
	nRows = atoi(fgets(dummy,10,fp));
	fclose(fp);
	int* testArray = CreateHouse(Make2DArray(nRows));
	for(int i=0;i<nRows;i++){
			printf("|");
				for(int j=0;j<nRows;j++){
					printf("%d",*(testArray+i*nRows+j));
				}
			printf("|\n");
			}
		fflush(stdin);
		printf("Is this the same as House1.txt?(y/n): ");
		fflush(stdout);
		char a = getchar();
		if (a == 'y'){
			ok = true;
			}

		return ok;
}

bool testCreateRooms(){
	bool ok=false;
	Room* testRooms = CreateRooms();
	char dummy[0];
	FILE* fp = fopen("houseGraph.txt","r");
	int nRows = atoi(fgets(dummy,100,fp));
	fclose(fp);
	for(int i=0; i<nRows;i++){
		printf("Room %d: %d, ",i,(testRooms+i)->treasure);
	}
	printf("\n");
	fflush(stdin);
	printf("Are these the correct treasure amounts for each room?(y/n): ");
	fflush(stdout);
	char a = getchar();
	if (a == 'y'){
		ok = true;
	}
	for(int i=0;i<nRows;i++){
		if(((testRooms+i)->visited)==true){
			ok = false;
		}
	}
	return ok;
}

bool testSetTotalRoomsTreasure(){
	int* TotalRooms=(int*)malloc(sizeof(int));
	int* TotalTreasure=(int*)malloc(sizeof(int));

	char* argTest1[4];
	argTest1[2]="2";
	SetTotalRoomsTreasure(3,argTest1, TotalRooms, TotalTreasure);
	bool ok1 = (*TotalRooms == 2);
	bool ok2 = (*TotalTreasure == 3);

	char* argTest2[4];
	argTest2[2]="2";
	argTest2[3]="3";
	SetTotalRoomsTreasure(4,argTest2, TotalRooms, TotalTreasure);
	bool ok3 = (*TotalRooms == 2);
	bool ok4 = (*TotalTreasure == 3);

	char* argTest3[4];
	SetTotalRoomsTreasure(2,argTest3, TotalRooms, TotalTreasure);
	bool ok5 = (*TotalRooms == 2);
	bool ok6 = (*TotalTreasure == 3);
	return ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
}

bool testDisplayRoomChoices(){
	FILE* fp = fopen("houseGraph.txt","r");
	char dummy[0];
	int nRows = atoi(fgets(dummy,100,fp));
	fclose(fp);
	int* testRooms1 = DisplayRoomChoices(0,CreateHouse(Make2DArray(nRows)));
	bool ok0 = (*testRooms1==1);
	bool ok1 = (*(testRooms1+1)==0);
	bool ok2 = (*(testRooms1+2)==0);
	bool ok3 = (*(testRooms1+3)==1);
	bool ok4 = (*(testRooms1+4)==1);
	bool ok5 = (*(testRooms1+5)==0);

	int* testRooms2 = DisplayRoomChoices(5,CreateHouse(Make2DArray(nRows)));
	bool ok05 = (*testRooms2==0);
	bool ok15 = (*(testRooms2+1)==0);
	bool ok25 = (*(testRooms2+2)==0);
	bool ok35 = (*(testRooms2+3)==0);
	bool ok45 = (*(testRooms2+4)==0);
	bool ok55 = (*(testRooms2+5)==1);
	return ok0 && ok1 && ok2 && ok3 && ok4 && ok5 && ok05 && ok15 && ok25 && ok35 && ok45 && ok55;
}

bool testRoomIsConnected(){
	FILE* fp = fopen("houseGraph.txt","r");
	char dummy[0];
	int nRows = atoi(fgets(dummy,100,fp));
	fclose(fp);
	bool ok1 = RoomIsConnected(0,3,CreateHouse(Make2DArray(nRows)));
	bool ok2 = !RoomIsConnected(5,3,CreateHouse(Make2DArray(nRows)));
	bool ok3 = RoomIsConnected(3,0,CreateHouse(Make2DArray(nRows)));
	bool ok4 = RoomIsConnected(4,2,CreateHouse(Make2DArray(nRows)));
	bool ok5 = !RoomIsConnected(2,0,CreateHouse(Make2DArray(nRows)));
	return ok1 && ok2 && ok3 && ok4 && ok5;
}

bool testCollectTreasure(){
	Room* testrooms = CreateRooms();
	int testtreasure = 0;
	testtreasure = CollectTreasure(testrooms,testtreasure);
	bool ok1 = (testtreasure==5);
	testtreasure = CollectTreasure((testrooms+5),testtreasure);
	bool ok2 = (testtreasure==5);
	testtreasure = CollectTreasure((testrooms),testtreasure);
	bool ok3 = (testtreasure==5);
	testtreasure = CollectTreasure((testrooms+1),testtreasure);
	bool ok4 = (testtreasure==27);
	return ok1 && ok2 && ok3 && ok4;
}

bool testChooseRoom(){
	FILE* fp = fopen("houseGraph.txt","r");
	char dummy[0];
	int nRows = atoi(fgets(dummy,100,fp));
	fclose(fp);

	int current=0;
	int chosen=3;
	int* currentRooms=(int*)malloc(sizeof(int));
	*currentRooms=0;
	int* currentTreasure=(int*)malloc(sizeof(int));
	*currentTreasure=0;
	Room* rooms = CreateRooms();
	int* layout = CreateHouse(Make2DArray(nRows));

	int nextRoom = ChooseRoom(current, chosen, currentRooms, currentTreasure, rooms, layout);
	bool ok1 = (nextRoom == chosen);
	bool ok2 = (*currentRooms == 1);
	bool ok3 = (*currentTreasure == 3);

	int nextRoom1 = ChooseRoom(5, 3, currentRooms, currentTreasure, rooms, layout);
	bool ok4 = (nextRoom1 == 5);
	bool ok5 = (*currentRooms == 1);
	bool ok6 = (*currentTreasure == 3);

	int nextRoom2 = ChooseRoom(3, 4, currentRooms, currentTreasure, rooms, layout);
	bool ok7 = (nextRoom2 == 4);
	bool ok8 = (*currentRooms == 2);
	bool ok9 = (*currentTreasure == 5);
	return ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;
}

bool testTooManyRoomsTreasure(){
	int* TotalRooms=(int*)malloc(sizeof(int));
	int* TotalTreasure=(int*)malloc(sizeof(int));
	int* currRooms=(int*)malloc(sizeof(int));
	int* currTreasure=(int*)malloc(sizeof(int));
	*TotalRooms=3;
	*TotalTreasure=6;
	*currRooms=0;
	*currTreasure=0;
	bool ok1 = !TooManyRoomsTreasure(currRooms,currTreasure,TotalRooms,TotalTreasure);
	*currRooms=3;
	bool ok2 = TooManyRoomsTreasure(currRooms,currTreasure,TotalRooms,TotalTreasure);
	*currRooms=0;
	*currTreasure=6;
	bool ok3 = TooManyRoomsTreasure(currRooms,currTreasure,TotalRooms,TotalTreasure);
	*currRooms=10;
	*currTreasure=10;
	bool ok4 = TooManyRoomsTreasure(currRooms,currTreasure,TotalRooms,TotalTreasure);
	return ok1 && ok2 && ok3 && ok4;
}

bool testPrintRoomsTreasure(){
	bool ok = false;
	int rooms = 3;
	int* treasure = (int*)malloc(sizeof(int));
	*treasure=27;
	PrintRoomsTreasure(rooms, treasure);
	fflush(stdin);
	printf("Is this a reasonable output?(y/n): ");
	fflush(stdout);
	char a = getchar();
	if (a == 'y'){
		ok = true;
	}
	return ok;
}
