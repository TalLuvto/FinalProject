//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_LIST_TESTS_H
#define PROJECT_LIST_TESTS_H

#include "MovesList.h"
#include "ErrorsHandlings.h"
#include "Types.h"
#include "stdio.h"
#include "stdlib.h"

//movesList getListFromUser();

//void makeEmptyList(movesList* lst);

//moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev);

//void insertDataToEndList(movesList* lst,Move move);

void _insertNewNodeToEnd(movesList* lst, moveCell* newNode);

void printList(movesList lst);

void _print_list(moveCell* node);

#endif
