//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "MovesArray.h"

void PrintMovesBoard(movesArray** moves) {
	char row_letter = 65;
	printf(" ");
	int i, j, k;
	for (j = 1; j < (M + 1); j++) {
		//		printf("    %d", j);
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		//		printf("%c", row_letter);
		for (int j = 0; j < M; j++) {
			for (k = 0; k < moves[i][j].size; k++) {
				printf("row: %d col: %d \n", moves[i][j].moves[k].rows, moves[i][j].moves[k].cols);
			}
			printf("\n");
		}
		row_letter++;
		printf("\n");
	}
}

void PrintBoard(char** board) {
	int i, j;
	char rowLetter = 'A';


	//	Print cols row:
	printf(" ");
	for (j = 1; j < (M + 1); j++) {
		printf("%*d", 4, j);
	}
	printf("\n");

	//    Print board:
	for (i = 0; i < N; i++) {
		printf("%c", rowLetter++); //print rows col
		for (j = 0; j < M; j++) {
			if (board[i][j] == TAKEN || board[i][j] == BLOCKED || board[i][j] == ' ')
				printf("%*c", 4, board[i][j]);
			else
				printf("%*d", 4, board[i][j]);
		}
		printf("\n");
	}
}

void initMovesArray(movesArray** moves) {
int i, j;
//#define basicTest
#define coverAllBoard

#ifdef basicTest
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 && j == 0)
				moves[i][j].size = 5;
			else
				moves[i][j].size = 4;
			moves[i][j].moves = (Move*)malloc(sizeof(Move) * moves[i][j].size);
			moves[i][j].moves[0].rows = 2;
			moves[i][j].moves[0].cols = -2;
			moves[i][j].moves[1].rows = -2;
			moves[i][j].moves[1].cols = -2;
			moves[i][j].moves[2].rows = 2;
			moves[i][j].moves[2].cols = 2;
			moves[i][j].moves[3].rows = -2;
			moves[i][j].moves[3].cols = 2;
		}
	}

	//moves[0][0].moves[4].rows = 2;
	//moves[0][0].moves[4].cols = 1;

#endif

#ifdef coverAllBoard
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			moves[i][j].size = 1;
			moves[i][j].moves = (Move*)malloc(sizeof(Move) * moves[i][j].size);
			moves[i][j].moves[0].rows = 1;
			moves[i][j].moves[0].cols = 1;
		}
	}

	//    All board path
	moves[0][1].moves[0].rows = 0; //A2
	moves[0][1].moves[0].cols = 2;
	moves[0][3].moves[0].rows = 0; //A4
	moves[0][3].moves[0].cols = -3;
	moves[0][0].moves[0].rows = 1; //A1
	moves[0][0].moves[0].cols = 1;
	moves[1][1].moves[0].rows = 0; //B2
	moves[1][1].moves[0].cols = 2;
	moves[1][3].moves[0].rows = 0; //B4
	moves[1][3].moves[0].cols = -1;
	//Last = B3
#endif

}

boardPosArray** validMoves(movesArray** moves, char** board) {
	boardPosArray** res;
	int i, j;

	res = (boardPosArray**)malloc(sizeof(boardPosArray*) * N);
	for (i = 0; i < N; i++) {
		res[i] = (boardPosArray*)malloc(sizeof(boardPosArray) * M);
		for (j = 0; j < M; j++) {
			int logsize = 0;
			Move* temp = (Move*)malloc(sizeof(Move) * moves[i][j].size);
			res[i][j].positions = (boardPos*)malloc(sizeof(boardPos) * moves[i][j].size);

			int indexMoves = 0;
			int indexPos = 0;
			while (indexMoves < moves[i][j].size) {
				if (isValid(board, moves[i][j].moves[indexMoves], i, j)) {
					temp[logsize].rows = moves[i][j].moves[indexMoves].rows;
					temp[logsize].cols = moves[i][j].moves[indexMoves].cols;
					logsize++;
					res[i][j].positions[indexPos][0] = i + moves[i][j].moves[indexMoves].rows + 'A';
					res[i][j].positions[indexPos][1] = j + moves[i][j].moves[indexMoves].cols + '1';
					indexPos++;
				}
				indexMoves++;
			}
			if (logsize < indexMoves) {
				temp = (Move*)realloc(temp, (sizeof(Move)) * logsize);
				res[i][j].positions = (boardPos*)realloc(res[i][j].positions, (sizeof(boardPos)) * logsize);
				moves[i][j].size = logsize;
				res[i][j].size = logsize;
			}

			free(moves[i][j].moves);
			moves[i][j].moves = temp;

		}
	}
	return res;
}


BOOL isValid(char** board, Move cellDest, int i, int j) {
	char rowDest = cellDest.rows;
	char colDest = cellDest.cols;

	if (i + rowDest >= N || i + rowDest < 0 || j + colDest >= M || j + colDest < 0)
		return FALSE;
	else if (board[i + rowDest][j + colDest] != ' ')
		return FALSE;
	else
		return TRUE;
}