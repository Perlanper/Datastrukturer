#pragma once

typedef struct element_t
{
	vertex *vertex;
	struct element_t *next;
	struct element_t *prev;
}element;

typedef struct list_t
{
	element *sentinel;
	int size;
}list;

list* NEW_LIST();
//element* NEW_ELEM(int k);
void LIST_INSERT(list *L, element *x);
element* NEW_VERTEX_ELEM(vertex *v);
