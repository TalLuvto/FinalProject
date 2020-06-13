//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include <stdio.h>
#include <stdlib.h>

void checkMemoryAllocation(void* ptr) {
	if (ptr == NULL) {
		printf("ERROR: Memery allocation failed!");
		exit(1);
	}
}