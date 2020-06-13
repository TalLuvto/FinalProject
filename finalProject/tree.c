//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "tree.h"

pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board) {
	pathTree path;
	char** boardCopy = (char**)malloc(sizeof(char*) * N);
	copyBoard(board, boardCopy, start);
	validMoves(moves, board);
	//    Declaring tree source :
	path.head = (treeNode*)malloc(sizeof(treeNode));
	path.head->position[0] = start[0];
	path.head->position[1] = start[1];
	path.head->next_possible_positions = NULL;
	path.head = _findAllPossiblePaths(boardCopy, moves, start, path.head);
	return path;
}

treeNode* _findAllPossiblePaths(char** board, movesArray** moves, boardPos start, treeNode* node) {
	int startCol = start[1] - 1;
	int startRow = changeInCapitals(start[0]);
	int logSize = 0;
	boardPos changesInBoard[M * N];
	unsigned int numOfChild = moves[startRow][startCol].size;

	if (node == NULL && numOfChild != 0) {
		node = (treeNode*)malloc(sizeof(treeNode));
		node->position[0] = start[0];
		node->position[1] = start[1];
		node->next_possible_positions = NULL;
	}

	printf("\n%c%d ", start[0], start[1]); //TODO: Remove before submission
	printf("Node's position: %c%d ", node->position[0], node->position[1]); //TODO: Remove before submission
	printf("\nInner list:\n"); //TODO: Remove before submission

	for (unsigned int i = 0; i < numOfChild; i++) { //Runs as long as there are children to the boardPos
		int k = changeInCapitals(start[0]);
		int t = start[1] - 1;
		if (isValid(board, moves[startRow][startCol].moves[i], k, t)) {
			if (isEmptyList(node->next_possible_positions)) {
				node->next_possible_positions = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
				node->next_possible_positions->next = NULL;
				node->next_possible_positions->node = NULL;
			}
			addCellToPath(board, start, moves[startRow][startCol].moves[i], TAKEN);
			node->next_possible_positions = insertValidPosToHead(node->next_possible_positions, start);
			printf("%c%d ", start[0], start[1]); //TODO: Remove before submission
			changesInBoard[logSize][0] = start[0];
			changesInBoard[logSize++][1] = start[1];
			node->next_possible_positions->node = _findAllPossiblePaths(board, moves, start, node->next_possible_positions->node);

			//Return to original parameters:
			start[0] -= moves[startRow][startCol].moves[i].rows;
			start[1] -= moves[startRow][startCol].moves[i].cols;
			removeTakenPos(board, changesInBoard, logSize); //TODO: Check failure
		}
	}
	return node;
}

treeNodeListCell* insertValidPosToHead(treeNodeListCell* lst, boardPos data) {
	treeNodeListCell* newListCell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	newListCell->node = createNode(data, NULL);
	newListCell->next = lst;
	return newListCell;
}

treeNode* createNode(boardPos data, treeNodeListCell* nextPossiblePosition) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->position[0] = data[0];
	newNode->position[1] = data[1];
	newNode->next_possible_positions = nextPossiblePosition;
	return newNode;
}

void removeTakenPos(char** board, boardPos posToRemove[], int size) {
	for (int i = 0; i < size; i++) {
		int startCol = posToRemove[i][1] - 1;
		int startRow = changeInCapitals(posToRemove[i][0]);
		board[startRow][startCol] = ' ';
	}
}