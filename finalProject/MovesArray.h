//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef MovesArray
#define MovesArray
#include <stdio.h>
#include <stdlib.h>
#include "Types.h"

void PrintMovesBoard(movesArray** moves);
void PrintBoard(char** board);
void initMovesArray(movesArray** moves);
boardPosArray** validMoves(movesArray** moves, char** board);
int isValid(char** board, Move cellDest, int i, int j);
#endif
