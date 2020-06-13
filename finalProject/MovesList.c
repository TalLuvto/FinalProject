//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "MovesList.h"
#include "MovesArray.h"

int display(movesList* moves_list, boardPos start, char** board) {
	char** boardCopy = (char**)malloc(sizeof(char*) * N);
	checkMemoryAllocation(boardCopy);
	copyBoard(board, boardCopy, start);
	int counter = 0;
	char index = 1;
	moveCell* currMoveCell = moves_list->head;

	while (currMoveCell != NULL) {
		if (isValid(boardCopy, currMoveCell->move, changeInCapitals(start[0]), start[1] - 1)) {
			addCellToPath(boardCopy, start, currMoveCell->move, index++);
			currMoveCell = currMoveCell->next;
		}
		else {
			removeMoveFromList(moves_list, &currMoveCell);
			counter++;
		}
	}

	PrintBoard(boardCopy);
	freeBoard(boardCopy);
	return counter;
}

void addCellToPath(char** board, boardPos currCell, Move move, char index) {
	currCell[0] += move.rows;
	currCell[1] += move.cols;
	board[changeInCapitals(currCell[0])][currCell[1] - 1] = index;
}

void copyBoard(char** orig, char** dest, boardPos start) {
	for (int i = 0; i < N; i++) {
		dest[i] = (char*)malloc(sizeof(char) * M);
		for (int j = 0; j < M; j++)
			dest[i][j] = orig[i][j];
	}
	int row = changeInCapitals(start[0]); //TODO: DEBUG ONLY !!!!! Remove before submission
	int col = start[1] - 1; //TODO: DEBUG ONLY !!!!! Remove before submission
	dest[changeInCapitals(start[0])][start[1] - 1] = TAKEN; //Set start position
}

void removeMoveFromList(movesList* moves_List, moveCell** toRemove) {
	moveCell* temp = *toRemove;
	if ((*toRemove)->prev == NULL && (*toRemove)->next == NULL) { //current cell is the only cell in the list
		moves_List->head = moves_List->tail = NULL;
	}
	else if ((*toRemove)->prev == NULL) { //current cell is head
		moves_List->head = (*toRemove)->next;
		moves_List->head->prev = NULL;
	}
	else if ((*toRemove)->next == NULL) { //current cell is tail
		moves_List->tail = (*toRemove)->prev;
		moves_List->tail = NULL;
	}
	else {
		(*toRemove)->prev->next = (*toRemove)->next;
		(*toRemove)->next->prev = (*toRemove)->prev;
	}
	*toRemove = (*toRemove)->next;
	free(temp);
}

void freeMovesList(movesList* moves_list) {
	_freeMovesList(moves_list->head);
}

void _freeMovesList(moveCell* moveNode) {
	moveCell* temp;
	while (moveNode != NULL) {
		temp = moveNode;
		moveNode = moveNode->next;
		free(temp);
	}
}

void freeBoard(char** board) {
	for (int i = 0; i < N; i++)
		free(board[i]);
	free(board);
}

void makeEmptyList(movesList* lst) {
	lst->head = lst->tail = NULL;
}