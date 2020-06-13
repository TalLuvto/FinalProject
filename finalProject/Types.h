//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_TYPES_H
#define PROJECT_TYPES_H

//General types:

//TODO: remove if redundant
//This MACRO converts a char of integer into an int type
#define parseInt(char) (char - '0')

//This MACRO converts a capital letter into it's ASCII
#define changeInCapitals(char) (char - 'A')

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define TAKEN '#'
#define BLOCKED '*'
#define EOS '\0' //End Of String TODO: remove if redundant


// Board types:
#define N 8 //Board's rows
#define M 8 //Board's cols

typedef char boardPos[2];
typedef unsigned char BYTE;

typedef struct _boardPosArray {
	unsigned int size;
	boardPos* positions;
}boardPosArray;


// Move types:
typedef struct _move {
	char rows, cols;
}Move;

typedef struct _movesArray {
	unsigned int size;
	Move* moves;
}movesArray;


typedef struct _moveCell {
	Move move;
	struct _moveCell* next;
	struct _moveCell* prev;
}moveCell;


typedef struct _movesList {
	moveCell* head;
	moveCell* tail;
}movesList;


typedef struct _treeNodeListCell treeNodeListCell;

typedef struct _treeNode {
	boardPos position;
	treeNodeListCell* next_possible_positions; //Brothers
}treeNode;

typedef struct _treeNodeListCell { //Brothers
	treeNode* node; //Son
	struct _treeNodeListCell* next;
}treeNodeListCell;

typedef struct _pathTree {
	treeNode* head;
}pathTree;

#endif
