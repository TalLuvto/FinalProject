//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_TREE_H
#define PROJECT_TREE_H

#include "MovesList.h"
#include "MovesArray.h"
#include "stdio.h"
#include "stdlib.h"
#include "ErrorsHandlings.h"

//TODO: Add description
#define isEmptyList(lst) (((lst) == NULL) ? TRUE : FALSE)

//TODO: Add description
pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board);

//TODO: Add description
treeNode* _findAllPossiblePaths(char** board, movesArray** moves, boardPos start, treeNode* node);

//TODO: Add description
treeNodeListCell* insertValidPosToHead(treeNodeListCell* lst, boardPos data);

//void insertValidPosToHead(treeNodeListCell* lst,boardPos data);

//TODO: Add description
treeNode* createNode(boardPos data, treeNodeListCell* nextPossiblePosition);

//TODO: Add description
void removeTakenPos(char** board, boardPos* posToRemove, int size);


#endif
