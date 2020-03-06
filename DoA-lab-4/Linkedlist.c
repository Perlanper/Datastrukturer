
#include"Graph.h"

#include <stdlib.h>
#include <stdio.h>
#include "Linkedlist.h"


list* NEW_LIST()
{
	list *L = malloc(sizeof(list));
	L->sentinel = malloc(sizeof(element));
	L->sentinel->next = L->sentinel;
	L->sentinel->prev = L->sentinel;
	L->size = 0;
	return L;
}

//element* NEW_ELEM(int k)
//{
//	element *E = malloc(sizeof(element));
//	E->key = k;
//	return E;
//}

void LIST_INSERT(list *L, element *x)
{
	x->next = L->sentinel->next;
	L->sentinel->next->prev = x;
	L->sentinel->next = x;
	x->prev = L->sentinel;
	L->size++;
}

element* NEW_VERTEX_ELEM(vertex *v)
{
	element *x = malloc(sizeof(element));
	x->vertex = v;
	return x;
}

