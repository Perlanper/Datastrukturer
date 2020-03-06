#pragma once
typedef struct element_t {
	int key;
	struct element_t *next;
	struct element_t *prev;
}element;

typedef struct List{
	element *sentinel;
	int size;
}list;

list* NEW_LIST();
element* NEW_ELEM(int k);
element* SEARCH_LIST(list* S, int k);
void INSERT(list* S, element* X);
element* DELETE(list *S, element *x);
int LIST_EMPTY(list *S);
element* PREDECESSOR(list* S, element *x);
element* SUCCESSOR(list* S, element* x);
element* MAXIMUM(list* S);
element* MINIMUM(list *S);
void PUSHBACK(list* S, element *x);
void LIST_PUSH(list *S, element *x);
element* LIST_POP(list *S);
void ENQUEUE_LIST(list *Q, element *x);
element* DEQUEUE_LIST(list *Q);
void LINKED_NPOW2(list *S, int k);
void PRINT_LIST(list *S);