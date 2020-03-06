#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist2.h"
#include "stack.h"
#include "queue.h"
#include "load_file.h"
#include "Insertsionsort.h"

//INSERTION SORT LINKED LIST(*)
//
//list* INSERTION_SORT_LIST(char* fName)
//{
//	list* S = NEWLIST_FROM_FILE(fName);
//	element *cmp;
//	element *temp;
//	element *nextinline;
//	
//	if (S->sentinel->next != S->sentinel)
//	{
//		temp = S->sentinel->next->next;
//		cmp = temp->prev;
//	}
//	while (temp != S->sentinel)
//	{
//		while (temp->key < cmp->key && cmp != S->sentinel)
//		{
//			cmp = cmp->prev;
//		}
//		if (temp->prev != cmp)
//		{
//			nextinline = temp->next;
//			INSERT_SORTED_ELEMENT(DELETE(S, temp), cmp);
//			temp = nextinline;
//			cmp = temp->prev;
//		}
//		else
//		{
//			temp = temp->next;
//			cmp = temp->prev;
//		}
//	}
//	PRINT_LIST(S);
//	return S;
//}
//
//void PRINT_LIST(list* S)
//{
//	element *x = S->sentinel->next;
//	while (x != S->sentinel)
//	{
//		printf("%d\n", x->key);
//		x = x->next;
//	}
//}
//void INSERT_SORTED_ELEMENT(element*temp, element *cmp)
//{
//	temp->prev = cmp;
//	temp->next = cmp->next;
//	temp->next->prev = temp;
//	cmp->next = temp;
//}
//
//list* NEWLIST_FROM_FILE(char* fname)
//{
//	const char* fName = fname;
//	int *a = load_file(fName);
//	list* lista = NEW_LIST();
//	int size = a[0];
//	for (int i = 1; i <= size; i++)
//	{
//		INSERT(lista, NEW_ELEM(a[i]));
//	}
//	return lista;
//}
//
//// INSERTION SORT ARRAY(*)
//
//intArrej* SORTARRAY(char *fname)
//{
//	intArrej *a = ARRAY_FROM_FILE(fname);
//	INSERTION_SORT_ARRAY(a);
//	PRINT_SORTED_ARRAY(a);
//	return a;
//}
//
//intArrej* ARRAY_FROM_FILE(char* fname)
//{
//	const char* fName = fname;
//	int *a = load_file(fName);
//	int size = a[0];
//	intArrej* array = NEW_ARRAY(size);
//	for (int i = 1; i <= size; i++)
//	{
//		ARRAY_PUSH(array, a[i]);
//	}
//	return array;
//}
//
//void INSERTION_SORT_ARRAY(intArrej *arr)
//{
//	arr->beg = arr->data;
//	int size = arr->size;
//	for (int j = 1; j < size; j++)
//	{
//		int key = arr->beg[j];
//		int i = j - 1;
//		while (i > -1 && arr->beg[i] > key)
//		{
//			arr->beg[i + 1] = arr->beg[i];
//			i = i - 1;
//		}
//		arr->beg[i + 1] = key;
//	}
//}
//
//void PRINT_SORTED_ARRAY(intArrej* arr)
//{
//	arr->beg = arr->data;
//	for (int i = 0; i < arr->size; i++)
//	{
//		printf("%d\n", arr->data[i]);
//	}
//}

