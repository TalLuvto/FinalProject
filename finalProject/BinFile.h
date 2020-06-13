//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_BINFILE_H
#define PROJECT_BINFILE_H

#include "MovesList.h"
#include "ErrorsHandlings.h"
#include "Types.h"
#include "stdio.h"
#include "stdlib.h"


void saveListToBinFile(char* file_name, boardPosArray* pos_arr);
void setBits(boardPosArray* pos_arr, BYTE res[], int j, int numOfPos);
void initArr(char c[], int size);



//void printBinFile();
bool ex5Test(char file_name[], char input_board_pos[], char output_board_pos[]);
boardPosArray* getBoardPosArrayPFromStr(char input[]);
void printBinFile(char* file_name);
boardPosArray* readArrayFromBin(char* file_name);

#endif