/*
 * tests.h
 *
 *  Created on: Sep 11, 2019
 *      Author: Eric Lopes
 */


#ifndef TESTS_H_
#define TESTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "production.h"

bool tests();
bool testMake2DArray();
bool testCreateRooms();
bool testCreateHouse();
bool testSetTotalRoomsTreasure();
bool testDisplayRoomChoices();
bool testRoomIsConnected();
bool testCollectTreasure();
bool testChooseRoom();
bool testTooManyRoomsTreasure();
bool testPrintRoomsTreasure();

#endif /* TESTS_H_ */
