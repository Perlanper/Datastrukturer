#include "Mergesort.h"
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist2.h"
#include "stack.h"
#include "queue.h"
#include "load_file.h"
#include "Insertsionsort.h"

//list* MERGE(list *S, list *L, list *R)
//{
//	while (L->sentinel->next != L->sentinel && R->sentinel->next != R->sentinel)
//	{
//		if (L->sentinel->next->key <= R->sentinel->next->key)
//		{
//			PUSHBACK(S, DELETE(L, L->sentinel->next));
//		}
//		else
//		{
//			PUSHBACK(S, DELETE(R, R->sentinel->next));
//		}
//	}
//	while (L->sentinel->next != L->sentinel)
//	{
//		PUSHBACK(S, DELETE(L, L->sentinel->next));
//	}
//	while (R->sentinel->next != R->sentinel)
//	{
//		PUSHBACK(S, DELETE(R, R->sentinel->next));
//	}
//	return S;
//}
//
//list* MERGE_SORT(list *S)
//{
//	if (S->size == 1)
//	{
//		return S;
//	}
//	int n1, n2;
//	list *L = NEW_LIST();
//	list *R = NEW_LIST();
//
//	if (S->size % 2 == 0)
//	{
//		n1 = n2 = S->size / 2;
//		for (int i = 0; i < n1; i++)
//		{
//			INSERT(L, DELETE(S, S->sentinel->next));
//		}
//		for (int j = 0; j < n2; j++)
//		{
//			INSERT(R, DELETE(S, S->sentinel->next));
//		}
//	}
//	else
//	{
//		n1 = S->size / 2;
//		n2 = n1 + 1;
//		for (int i = 0; i < n1; i++)
//		{
//			INSERT(L, DELETE(S, S->sentinel->next));
//		}
//		for (int j = 0; j < n2; j++)
//		{
//			INSERT(R, DELETE(S, S->sentinel->next));
//		}
//
//	}
//	L = MERGE_SORT(L);
//	R = MERGE_SORT(R);
//	S = MERGE(S, L, R);
//	return S;
//}
//
//list* MERGE_SORTING(char* fname)
//{
//	list *S = NEWLIST_FROM_FILE(fname);
//	 S = MERGE_SORT(S);
//	 PRINT_LIST(S);
//	return S;
//}