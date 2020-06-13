//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601


#ifndef PATHFROMFILE_H
#define PATHFROMFILE_H

#include "MovesList.h"
#include "ErrorsHandlings.h"
#include "Types.h"
#include "stdio.h"
#include "stdlib.h"
#include "MovesArray.h"
#include "tree.h"
#include "PathCalculation.h"

//Todo: Add description
int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board);


boardPos* readFromBinFile(char* file_name, int* size);

#endif