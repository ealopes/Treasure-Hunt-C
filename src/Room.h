/*
 * Room.h
 *
 *  Created on: Sep 11, 2019
 *      Author: Eric Lopes
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef ROOM_H_
#define ROOM_H_

typedef struct Room{
	int treasure;
	bool visited;
}Room;

Room* CreateRooms();
bool RoomIsConnected(int current, int chosen, int* layout);
int CollectTreasure(Room* room,int currentTreasure);


#endif /* ROOM_H_ */
