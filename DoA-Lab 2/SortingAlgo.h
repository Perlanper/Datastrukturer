#pragma once

void INSERT_SORTED_ELEMENT(element*temp, element *cmp);
list* NEWLIST_FROM_FILE(char* fname);
void PRINT_LIST2(list* S);
list* INSERTION_SORT_LIST(char* fName);
void INSERTION_SORT_ARRAY(intArrej *arr);
void PRINT_SORTED_ARRAY(intArrej* arr);
intArrej* ARRAY_FROM_FILE(char* fname);
intArrej* SORTARRAY(char *fname);
list* MERGE(list *S, list *L, list *R);
list* MERGE_SORT(list *S);
list* MERGE_SORTING(char* fname);
int PARTITION_ARRAY(intArrej *arr, int p, int r);
intArrej* QUICKSORT_ARRAY(intArrej *arr, int p, int r);
intArrej* QUICK_SORTING_ARRAY(char* fname);

