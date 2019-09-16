/*
 * House.h
 *
 *  Created on: Sep 12, 2019
 *      Author: eric0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Room.h"

#ifndef HOUSE_H_
#define HOUSE_H_

int* Make2DArray(int nRows);
int* CreateHouse();
void SetTotalRoomsTreasure(int argc, char* argv[], int* TotalRooms, int* TotalTreasure);
void EnterHouse();
int* DisplayRoomChoices(int current, int* array);
int ChooseRoom(int current, int chosen, int* currentRooms, int* currentTreasure, Room* rooms, int* layout);
bool TooManyRoomsTreasure(int* rooms, int* treasure, int* maxRooms, int* maxTreasure);
void PrintRoomsTreasure(int room, int* treasure);


#endif /* HOUSE_H_ */
