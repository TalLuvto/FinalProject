//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601
#define _CRT_SECURE_NO_WARNINGS
#include "BinFile.h"
void saveListToBinFile(char* file_name, boardPosArray* pos_arr) {
	unsigned int j = 0;
	BYTE c[3] = { 0,0,0 };
	unsigned int lenName = strlen(file_name) + 5;
	char* file = (char*)malloc(sizeof(char) * lenName);
	checkMemoryAllocation(file);
	sprintf(file, "%s%s", file_name, ".bin");
	FILE* fb;
	fb = fopen(file, "wb");
	free(file);

	fwrite(&pos_arr->size, sizeof(short), 1, fb);
	int index = pos_arr->size;
	while (j < pos_arr->size) {
		initArr(c, 3);
		if (index < 4) {
			setBits(pos_arr, c, j, index%4);
			fwrite(c, sizeof(BYTE), index%4, fb);
			j += pos_arr->size;
		}
		else {
			setBits(pos_arr, c, j,4);
			fwrite(c, sizeof(BYTE), 4, fb);
			index -= 4;
			j += 4;
		}
	}

	fclose(fb);
}

void setBits(boardPosArray* pos_arr, BYTE res[], int j,int numOfPos) {
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

void initArr(char c[],int size) {
	for (int i = 0; i < size; i++)
		c[i] = 0;
}

bool ex5Test(char file_name[], char input_board_pos[], char output_board_pos[]) {

	bool test = false;
	boardPosArray* bp_arr = getBoardPosArrayPFromStr(input_board_pos);
	saveListToBinFile(file_name, bp_arr);
	boardPosArray* result = readArrayFromBin(file_name);
	boardPosArray* bp_arr_output = (output_board_pos == NULL ? bp_arr : getBoardPosArrayPFromStr(output_board_pos));

	if (result->size != bp_arr_output->size)
		test = true;
	for (int i = 0; i < result->size && !test; i++)
		if ((result->positions[i][0] != bp_arr_output->positions[i][0]) ||
			result->positions[i][1] != bp_arr_output->positions[i][1])
			test = true;

	if (test) {
		printf("mistake at comparing boardPos`s.\n");
		printBinFile(file_name);
		printf("\n");
	}

	free(bp_arr->positions);
	free(bp_arr);
	free(result->positions);
	free(result);
	return !test;
}


boardPosArray* getBoardPosArrayPFromStr(char input[]) {

	// "<3> (A,1) (C,2) (E,3)"
	boardPosArray* result = (boardPosArray*)malloc(sizeof(boardPosArray));
	checkMemoryAllocation(result);
	sscanf(input, "<%d>", &result->size);
	input += 4;
	result->positions = (boardPos*)calloc(result->size, sizeof(boardPos));
	checkMemoryAllocation(result->positions);

	char row;
	int col, counter = 0;
	for (int i = 0; i < strlen(input); i++)
		if (input[i] == '(') {
			sscanf(&input[i], "(%c,%d)", &row, &col);
			result->positions[counter][0] = row;
			result->positions[counter++][1] = col;
		}

	return result;
}


void printBinFile(char* file_name) {

	boardPosArray* result = readArrayFromBin(file_name);
	printf(" // RES      - <%d>", result->size);
	for (int i = 0; i < result->size; i++)
		printf(" (%c,%d)", result->positions[i][0], result->positions[i][1]);

	free(result->positions);
	free(result);
}


//void printBinFile() {
//	FILE* data = fopen("test2.bin", "rb");
//	short int numOfPos;
//	fread(&numOfPos, sizeof(short int), 1, data);
//	char* arr = (char*)malloc(sizeof(char) * 8);
//
//	fread(stdout, sizeof(unsigned char), 7, data);
//}
//


boardPosArray* readArrayFromBin(char* file_name) {
	unsigned int lenName = strlen(file_name) + 5;
	char* file = (char*)malloc(sizeof(char) * lenName);
	sprintf(file, "%s%s", file_name, ".bin");
	FILE* data = fopen(file, "rb");
	checkMemoryAllocation(data);
	short int len;
	fread(&len, sizeof(short int), 1, data);

	boardPosArray* result = (boardPosArray*)calloc(1, sizeof(boardPosArray));
	checkMemoryAllocation(result);
	result->size = len;
	result->positions = (boardPos*)calloc(len, sizeof(boardPos));
	checkMemoryAllocation(result->positions);

	int type = 0;
	BYTE currByte, mask = 0x07, input, temp;
	fread(&currByte, sizeof(BYTE), 1, data);
	for (int nextEmptyBit = 0; nextEmptyBit < len * 6; nextEmptyBit += 3) {
		if (nextEmptyBit > 1 && nextEmptyBit % 8 == 0)
			fread(&currByte, sizeof(BYTE), 1, data);
		int bitIndex = 7 - (nextEmptyBit % 8), resIndex = nextEmptyBit / 6;
		if (bitIndex >= 2) {
			input = (currByte & (mask << (bitIndex - 2))) >> (bitIndex - 2);
			temp = input + (type == 0 ? 'A' : 1);
			result->positions[resIndex][type] |= temp;
		}
		else {
			input = ((currByte & (mask >> (2 - bitIndex))) << (2 - bitIndex));
			fread(&currByte, sizeof(BYTE), 1, data);
			temp = ((currByte & (mask << (6 + bitIndex))) >> (6 + bitIndex));
			input |= temp;
			result->positions[resIndex][type] |= input + (type == 0 ? 'A' : 1);
		}
		type = (type == 1 ? 0 : 1);
	}

	fclose(data);
	return result;
}