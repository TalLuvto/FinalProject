//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601
#define _CRT_SECURE_NO_WARNINGS
#include "MovesArray.h"
#include "MovesList.h"
#include "List_Tests.h"
#include "Types.h"
#include "tree.h"
#include "PathCalculation.h"
#include "BinFile.h"

void printTree(pathTree tree);
void printTreeAux(treeNode* node);

//#define question1
//#define question2
//#define question3
//#define question4
//#define question5
//#define question5Amit
#define question6

int main() {

	char* board[] = { "  *  ",
					  "*    ",
					  "    *",
					  "  * *" };

	char* boardMini[] = { "  * ","*   " };

	char* emptyBoard[] = { "     ",
						   "     ",
						   "     ",
						   "     " };

	///////////////    Question 1 tests:    ///////////////
#ifdef question1
	movesArray** moves;
	boardPosArray** positionsArray;
	int i, j;
	moves = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	initMovesArray(moves);
	PrintBoard(board);
	printf("\n");
	PrintMovesBoard(moves);
	printf("\n");
	positionsArray = validMoves(moves, board);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int indexPos = 0;
			while (indexPos < positionsArray[i][j].size) {
				printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray[i][j].positions[indexPos][0], positionsArray[i][j].positions[indexPos][1]);
				printf("\n");
				indexPos++;
			}
		}
	}
#endif

	///////////////    Question 2 tests:    ///////////////
#ifdef question2
	boardPos start = { 'A',2 };
	movesList list = getListFromUser();
	printList(list);

	int removedCells = display(&list, start, board);
	printf("Number of invalid moves that were removed: %d", removedCells);

#endif question2

	///////////////    Question 3 tests:    ///////////////
#ifdef question3
	movesArray** moves3;
	pathTree tree;
	boardPos start;
	boardPosArray** positionsArray3;
	int i, j;
	moves3 = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves3[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	start[0] = 'C';
	start[1] = 3;

	initMovesArray(moves3);
	//    positionsArray3 = validMoves(moves3,board);
	//    PrintMovesBoard(moves3);

	//    for (i = 0; i < N; i++){
	//        for (j = 0; j < M; j++){
	//            int indexPos = 0;
	//            while (indexPos < positionsArray3[i][j].size){
	//                printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray3[i][j].positions[indexPos][0], positionsArray3[i][j].positions[indexPos][1]);
	//                printf("\n");
	//                indexPos++;
	//            }
	//        }
	//    }

	tree = findAllPossiblePaths(start, moves3, board);
#endif question3

	///////////////    Question 4 tests:    ///////////////
#ifdef question4
	movesArray** moves4;
	boardPos start4;
	movesList* list;
	int i, j;
	moves4 = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++) {
		moves4[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	start4[0] = 'A';
	start4[1] = 2;

	initMovesArray(moves4);
	list = findPathCoveringAllBoard(start4, moves4, boardMini);

	if (list == NULL)
		printf("There is no path!");
	else
		printList(*list);
#endif

	///////////////    Question 5 tests:    ///////////////
#ifdef question5
	boardPosArray* arr = (boardPosArray*)malloc(sizeof(boardPosArray));
	arr->size = 3;
	arr->positions = (boardPos*)malloc(sizeof(boardPos) * arr->size);
	arr->positions[0][0] = 'A';
	arr->positions[0][1] = 2;
	arr->positions[0][0] = 'C';
	arr->positions[0][1] = 4;
	arr->positions[0][0] = 'B';
	arr->positions[0][1] = 3;

	saveListToBinFile("TalEliptital", arr);

#endif


	///////////////    Question 5Amit tests:    ///////////////
#ifdef question5Amit
	char boardPos_array_str[] = "<3> (A,1) (C,2) (E,5)";


	printf(" // Ex 5 Test 1 # EXPECTED -> GOOD\n                # RESULT   -> ");
	printf(ex5Test("test1", boardPos_array_str, NULL) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str);
	char boardPos_array_str1[] = "<9> (A,1) (C,2) (E,5) (A,2) (A,3) (B,8) (H,8) (H,1) (F,7)";

	printf(" // Ex 5 Test 2 # EXPECTED -> GOOD\n                # RESULT   -> ");
	printf(ex5Test("test2", boardPos_array_str1, NULL) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str1);

	printf(" // Ex 5 Test 3 # EXPECTED -> mistake at comparing boardPos`s.\n                # RESULT   -> ");
	printf(ex5Test("test3", boardPos_array_str1, boardPos_array_str) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str);

	printf(" // Ex 5 Test 4 # EXPECTED -> mistake at comparing boardPos`s.\n                # RESULT   -> ");
	printf(ex5Test("test4", boardPos_array_str, boardPos_array_str1) ? "GOOD\n\n" : " // EXPECTED - %s\n\n", boardPos_array_str1);

#endif

	///////////////    Question 6 tests:    ///////////////
#ifdef question6
	movesArray** moves;
	moves = (movesArray**)malloc(sizeof(movesArray*) * N);

	char* file_name = "test1.bin";
	checkAndDisplayPathFromFile(file_name, moves, board);

#endif

	exit(0);
}


void printTree(pathTree tree)
{
	treeNode* root = tree.head;

	printTreeAux(root);
}

void printTreeAux(treeNode* node)
{
	treeNodeListCell* curr = NULL;
	int i = 1;
	//TreeNodeListCell* head = NULL;

	if (node->next_possible_positions == NULL)
		return;
	else
	{
		printf("%c%c ", node->position[0], node->position[1]);
		//printf("|leveldown|");

		//head = node->next_possible_positions;

		curr = node->next_possible_positions;

		while (curr)
		{

			printTreeAux(curr->node);
			printf("nextBranch->");

			curr = curr->next;

			if (curr == NULL)
				printf("NULL");

			i++;
		}

		printf("\n");
	}

}