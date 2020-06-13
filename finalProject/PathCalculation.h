//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_PATHCALCULATION_H
#define PROJECT_PATHCALCULATION_H
#include "MovesArray.h"
#include "MovesList.h"
#include "Types.h"
#include "tree.h"
#include "List_Tests.h" //TODO: Remove before submission !!!!!!!!

//TODO: Add description
movesList* findPathCoveringAllBoard(boardPos start, movesArray** moves, char** board);

//TODO: Add description
int getCountOfEmptyCells(char** board);

//TODO: Add description
BOOL getAllBoardPath(treeNode* root, movesList* list, int levelCounter, int emptyCells);

//TODO: Add description
Move getLastMove(boardPos prev, boardPos curr);

//TODO: Add description
void insertDataToHead(movesList* lst, Move move);

//TODO: Add description
moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev);

//TODO: Add description
void _insertNewNodeHead(movesList* lst, moveCell* newNode);

#endif
