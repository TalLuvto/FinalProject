//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601


#include "PathCalculation.h"

movesList* findPathCoveringAllBoard(boardPos start, movesArray** moves, char** board) {
	movesList* list = (movesList*)malloc(sizeof(movesList));
	int levelCounter = 0;
	int numOfEmptyCells = getCountOfEmptyCells(board);
	pathTree allPossiblePaths = findAllPossiblePaths(start, moves, board);

	makeEmptyList(list);
	if (getAllBoardPath(allPossiblePaths.head, list, levelCounter, numOfEmptyCells))
		return list;
	else
		return NULL;
}

int getCountOfEmptyCells(char** board) {
	int counter = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == ' ')
				counter++;
			//counter += (board[i][j] == ' ') ? 1 : 0;
		}
	}
	counter--;
	return counter;
}

BOOL getAllBoardPath(treeNode* root, movesList* list, int levelCounter, int emptyCells) {
	if (root == NULL && (levelCounter != emptyCells)) {
		return FALSE;
	}
	else if (levelCounter == emptyCells) {
		return TRUE;
	}

	while (root->next_possible_positions != NULL) {
		if (getAllBoardPath(root->next_possible_positions->node, list, levelCounter + 1, emptyCells)) {
			Move move = getLastMove(root->position, root->next_possible_positions->node->position);
			insertDataToHead(list, move);
			return TRUE;
		}
		root->next_possible_positions = root->next_possible_positions->next;
	}
	return FALSE;
}

Move getLastMove(boardPos curr, boardPos next) {
	Move move;
	move.rows = next[0] - curr[0];
	move.cols = next[1] - curr[1];
	return move;
}


void insertDataToHead(movesList* lst, Move move) {
	moveCell* newNode = createMoveNode(move, lst->head, NULL);
	_insertNewNodeHead(lst, newNode);
}

moveCell* createMoveNode(Move move, moveCell* next, moveCell* prev) {
	moveCell* newNode = (moveCell*)malloc(sizeof(moveCell));
	checkMemoryAllocation(newNode);
	newNode->move = move;
	newNode->next = next;
	newNode->prev = prev;
	return newNode;
}

void _insertNewNodeHead(movesList* lst, moveCell* newNode) {
	if (lst->head == NULL) {
		lst->head = newNode;
	}
	else {
		newNode->next = lst->head;
		lst->head->prev = newNode;
		lst->head = newNode;
	}
}