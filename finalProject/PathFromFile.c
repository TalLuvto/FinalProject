//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "PathFromFile.h"

int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board) {
	int size;
	bool isExist;
	boardPos* arr= readFromBinFile(file_name, &size, &isExist);
	if (!isExist)
		return -1;

	boardPosArray** validPositions= validMoves(moves, board);
	if (isValidPos(validPositions, )) {
		//get move and add to list
	}
	else {
		return 1;
	}
	//Call display function ( question 2)

	list = findPathCoveringAllBoard(start4, moves4, boardMini);
	if (list == NULL)
		return 3;
	else
		return 2;
}

boardPos* readFromBinFile(char* file_name, int* size,bool* isExist) {
	FILE* fr = fopen(file_name, "rb");
	checkMemoryAllocation(fr);
	short int numOfPos;
	fread(&numOfPos, sizeof(short), 1, fr);
	BYTE byte;
	boardPos* arr = (boardPos*)malloc(sizeof(boardPos) * numOfPos);
	fread(&byte, sizeof(BYTE), 1, fr);
	arr[0][0] = getMask(5) & byte;
	arr[0][1] = getMask(5-3) & byte;
	arr[1][0] = getMask(-1) & byte;


	int index = numOfPos;
	int j = 0;
	while (j < numOfPos)
	{
		if (index < 4) {
			readBits(pos_arr, c, j, index % 4);
			fwrite(c, sizeof(BYTE), index % 4, fb);
			j += pos_arr->size;
		}

		else {
			setBits(pos_arr, c, j, 4);
			fwrite(c, sizeof(BYTE), 4, fb);
			index -= 4;
			j += 4;
		}
	}


}
BYTE getMask(int i) {
	BYTE mask = 0x07;
	if(i > 0)
		return mask << i;
	return mask >> -i;
}

void readBits(FILE* file, BYTE res[], int j, int numOfPos) {
	
	res[0] = ((pos_arr->positions[j][0] - 'A') << 5) | ((pos_arr->positions[j][1] - 1) << 2);
	if (numOfPos > 1) {
		res[0] |= (pos_arr->positions[j + 1][0] - 'A' >> 1);
		res[1] = (pos_arr->positions[j + 1][0] - 'A' << 7) | (pos_arr->positions[j + 1][1] - 1 << 4);
	}
	if (numOfPos > 2) {
		res[1] |= (pos_arr->positions[j + 2][0] - 'A' << 1) | (pos_arr->positions[j + 2][1] - 1 >> 2);
		res[2] = (pos_arr->positions[j + 2][1] - 1 << 6);
	}
	if (numOfPos > 3) {
		res[2] |= (pos_arr->positions[j + 3][0] - 'A' << 3) | (pos_arr->positions[j + 3][1] - 1);
	}

}

}

bool isValidPos(boardPosArray validPositions, boardPos next) {
	//Check that the given boardPos appears inside the validPositions->positions array
}






