#ifndef LOAD_FILE_H
#define LOAD_FILE

#include  "stdbool.h"
#define MAX_NUM_ELEMENTS		100000

int* load_file(const char* fName);
bool test_solution(const char* sol_fName, int* arr);

#endif
