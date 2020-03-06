#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist2.h"
#include "stack.h"
#include "queue.h"
#include "load_file.h"
#include "SortingAlgo.h"


//::::::::::::::::::INSERTION SORT LINKED LIST::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void INSERT_SORTED_ELEMENT(element*temp, element *cmp)
{
	temp->prev = cmp;
	temp->next = cmp->next;
	temp->next->prev = temp;
	cmp->next = temp;
}

list* NEWLIST_FROM_FILE(char* fname)
{
	const char* fName = fname;
	int *a = load_file(fName);
	list* lista = NEW_LIST();
	int size = a[0];
	for (int i = 1; i <= size; i++)
	{
		INSERT(lista, NEW_ELEM(a[i]));
	}
	return lista;
}

void PRINT_LIST2(list* S)
{
	element *x = S->sentinel->next;
	while (x != S->sentinel)
	{
		printf("%d ", x->key);
		x = x->next;
	}
}

list* INSERTION_SORT_LIST(char* fName)
{
	list* S = NEWLIST_FROM_FILE(fName);
	element *cmp;
	element *temp;
	element *nextinline;
	printf("BEFORE:   ");
	PRINT_LIST2(S);
	printf("\n");

	if (S->sentinel->next != S->sentinel)
	{
		temp = S->sentinel->next->next;
		cmp = temp->prev;
	}
	while (temp != S->sentinel)
	{
		while (temp->key < cmp->key && cmp != S->sentinel)
		{
			cmp = cmp->prev;
		}
		if (temp->prev != cmp)
		{
			nextinline = temp->next;
			INSERT_SORTED_ELEMENT(DELETE(S, temp), cmp);
			temp = nextinline;
			cmp = temp->prev;
		}
		else
		{
			temp = temp->next;
			cmp = temp->prev;
		}
	}
	printf("AFTER:    ");
	PRINT_LIST2(S);
	return S;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//:::::::::::::::::::::::::::::INSERTION SORT ARRAY::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void INSERTION_SORT_ARRAY(intArrej *arr)
{
	arr->beg = arr->data;
	int size = arr->size;
	for (int j = 1; j < size; j++)
	{
		int key = arr->beg[j];
		int i = j - 1;
		while (i > -1 && arr->beg[i] > key)
		{
			arr->beg[i + 1] = arr->beg[i];
			i = i - 1;
		}
		arr->beg[i + 1] = key;
	}
}

void PRINT_SORTED_ARRAY(intArrej* arr)
{
	arr->beg = arr->data;
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ", arr->data[i]);
	}
}

intArrej* ARRAY_FROM_FILE(char* fname)
{
	const char* fName = fname;
	int *a = load_file(fName);
	int size = a[0];
	intArrej* array = NEW_ARRAY(size);
	for (int i = 1; i <= size; i++)
	{
		ARRAY_PUSH(array, a[i]);
	}
	return array;
}

intArrej* SORTARRAY(char *fname)
{
	intArrej *a = ARRAY_FROM_FILE(fname);
	printf("BEFORE:   ");
	PRINT_SORTED_ARRAY(a);
	INSERTION_SORT_ARRAY(a);
	printf("\n");
	printf("AFTER:    ");
	PRINT_SORTED_ARRAY(a);
	return a;
}
//-------------------------------------------------------------------------------------------------------------------------
//:::::::::::::::::::::::::MERGESORTING::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

list* MERGE(list *S, list *L, list *R)
{
	while (L->sentinel->next != L->sentinel && R->sentinel->next != R->sentinel)
	{
		if (L->sentinel->next->key <= R->sentinel->next->key)
		{
			PUSHBACK(S, DELETE(L, L->sentinel->next));
		}
		else
		{
			PUSHBACK(S, DELETE(R, R->sentinel->next));
		}
	}
	while (L->sentinel->next != L->sentinel)
	{
		PUSHBACK(S, DELETE(L, L->sentinel->next));
	}
	while (R->sentinel->next != R->sentinel)
	{
		PUSHBACK(S, DELETE(R, R->sentinel->next));
	}
	return S;
}

list* MERGE_SORT(list *S)
{
	if (S->size == 1)
	{
		return S;
	}
	int n1, n2;
	list *L = NEW_LIST();
	list *R = NEW_LIST();

	if (S->size % 2 == 0)
	{
		n1 = n2 = S->size / 2;
		for (int i = 0; i < n1; i++)
		{
			INSERT(L, DELETE(S, S->sentinel->next));
		}
		for (int j = 0; j < n2; j++)
		{
			INSERT(R, DELETE(S, S->sentinel->next));
		}
	}
	else
	{
		n1 = S->size / 2;
		n2 = n1 + 1;
		for (int i = 0; i < n1; i++)
		{
			INSERT(L, DELETE(S, S->sentinel->next));
		}
		for (int j = 0; j < n2; j++)
		{
			INSERT(R, DELETE(S, S->sentinel->next));
		}

	}
	L = MERGE_SORT(L);
	R = MERGE_SORT(R);
	S = MERGE(S, L, R);
	return S;
}

list* MERGE_SORTING(char* fname)
{
	list *S = NEWLIST_FROM_FILE(fname);
	printf("BEFORE:   ");
	PRINT_LIST2(S);
	S = MERGE_SORT(S);
	printf("\n");
	printf("AFTER:    ");
	PRINT_LIST2(S);
	return S;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//::::::::::::::::::::::::::::::::QUICKSORT::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int PARTITION_ARRAY(intArrej *arr, int p, int r)
{
	int x = arr->data[r];
	int i = p - 1;
	int temp;
	for (int j = p; j <= r - 1; j++)
	{
		if (arr->data[j] <= x)
		{
			i++;
			temp = arr->data[j];
			arr->data[j] = arr->data[i];
			arr->data[i] = temp;
		}
	}
	temp = arr->data[r];
	arr->data[r] = arr->data[i + 1];
	arr->data[i + 1] = temp;
	return i + 1;
}

intArrej* QUICKSORT_ARRAY(intArrej *arr, int p, int r)
{
	if (p < r)
	{
		int q = PARTITION_ARRAY(arr, p, r);
		QUICKSORT_ARRAY(arr, p, q - 1);
		QUICKSORT_ARRAY(arr, q + 1, r);
	}
	return arr;
}

intArrej* QUICK_SORTING_ARRAY(char* fname)
{
	intArrej *arr = ARRAY_FROM_FILE(fname);
	printf("BEFORE:   ");
	PRINT_SORTED_ARRAY(arr);
	printf("\n");
	printf("AFTER:    ");
	QUICKSORT_ARRAY(arr, 0, arr->size - 1);
	PRINT_SORTED_ARRAY(arr);
	printf("\n");
	return arr;
}