#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist2.h"
#include "stack.h"
#include "queue.h"
#include "Insertsionsort.h"
#include "load_file.h"
#include "Mergesort.h"

//int PARTITION_ARRAY(intArrej *arr, int p, int r)
//{
//	int x = arr->data[r];
//	int i = p - 1;
//	int temp;
//	for (int j = p; j <= r - 1; j++)
//	{
//		if (arr->data[j] <= x)
//		{
//			i++;
//			temp = arr->data[j];
//			arr->data[j] = arr->data[i];
//			arr->data[i] = temp;
//		}
//	}
//	temp = arr->data[r];
//	arr->data[r] = arr->data[i + 1];
//	arr->data[i + 1] = temp;
//	return i + 1;
//}
//
//intArrej* QUICKSORT_ARRAY(intArrej *arr, int p, int r)
//{
//	if (p < r)
//	{
//		int q = PARTITION_ARRAY(arr, p, r);
//		QUICKSORT_ARRAY(arr, p, q - 1);
//		QUICKSORT_ARRAY(arr, q + 1, r);
//	}
//	return arr;
//}
//
//intArrej* QUICK_SORTING_ARRAY(char* fname)
//{
//	intArrej *arr = ARRAY_FROM_FILE(fname);
//	PRINT_SORTED_ARRAY(arr);
//	printf("\n");
//	QUICKSORT_ARRAY(arr, 0, arr->size - 1);
//	PRINT_SORTED_ARRAY(arr);
//	return arr;
//}