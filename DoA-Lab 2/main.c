#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Linkedlist2.h"
#include "queue.h"
#include "SortingAlgo.h"
#include "load_file.h"

int main()
{
	//EXERCISE 1
	printf("EXERCISE 1: INSERTION-SORT LINKED LIST\n");
	list *list1 = INSERTION_SORT_LIST("test-10-1-problem");
	printf("\n-------------------------------------------------\n");
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//EXERCISE 2
	printf("EXERCISE 2: INSERTION-SORT ARRAY\n");
	intArrej *arr1 = SORTARRAY("test-10-1-problem");
	printf("\n-------------------------------------------------\n");
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//EXERCISE 4
	printf("EXERCISE 4: MERGESORT LINKED LIST\n");
	list *list2 = MERGE_SORTING("test-10-1-problem");
	printf("\n-------------------------------------------------\n");
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//EXERCISE 7
	printf("EXERCISE 7: QUICKSORT ARRAY\n");
	intArrej *arr2 = QUICK_SORTING_ARRAY("test-10-1-problem");
	printf("-------------------------------------------------\n");
	system("pause");
}