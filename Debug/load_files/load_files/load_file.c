#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MAX_NUM_ELEMENTS		100000

#include "load_file.h"
#include "stdlib.h"

int* load_file(const char* fName)
{
	int input[MAX_NUM_ELEMENTS];
	int num_elements = 0;

	FILE* file = fopen(fName, "r");
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		input[num_elements++] = atoi(line);
		//printf("%d", atoi(line));
	}
	fclose(file);
	
	int* data = (int*)malloc((num_elements+1)*sizeof(int));
	for ( int i = 1 ; i <= num_elements ; i++ ) 
	{
		data[i] = input[i-1];
	}
	data[0] = num_elements;
	return data;
}


int test_solution(const char* sol_fName, int* arr){
    
    int* solution = load_file(sol_fName);
    int size = *solution; 
    solution = &solution[1];
    
    for(int i = 1 ; i <= size ;  ++i){
        
        if(*solution != *arr || arr==NULL)
            return 0;
        
        solution++;
        arr++;
        
    }
    
    return 1;
    
    
    
    
}



