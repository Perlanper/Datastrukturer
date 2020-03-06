#include "Linkedlist2.h"
#include <stdio.h>
#include <stdlib.h>

list* NEW_LIST()
{
	list* S = malloc(sizeof(list));
	S->sentinel = malloc(sizeof(element));
	S->sentinel->next = S->sentinel;
	S->sentinel->prev = S->sentinel;
	S->size = 0;
	return S;
}

element* NEW_ELEM(int k)
{
	element* E = malloc(sizeof(element));
	if (E == NULL)
	{
		printf("ALLOCATION ERROR\n");
	}
	E->key = k;
	return E;
}

element* SEARCH_LIST(list *S, int k)
{
	element *x = S->sentinel->next;
	while (x != S->sentinel && x->key != k)
	{
		x = x->next;
	}
	return x;
}

element* MINIMUM(list *S)
{
	element *x = S->sentinel->next;
	int temp = x->key;
	while (x != S->sentinel)
	{
		if (x->key < temp)
		{
			temp = x->key;
		}
		x = x->next;
	}
	return SEARCH_LIST(S, temp);
}

element* MAXIMUM(list* S)
{
	element*x = S->sentinel->next;
	int temp = x->key;
	while (x != S->sentinel)
	{
		if (x->key > temp)
		{
			temp = x->key;
		}
		x = x->next;
	}
	//printf("%d", (SEARCH_LIST(S, temp))->key);
	return SEARCH_LIST(S, temp);
}

element* SUCCESSOR(list* S, element* x)
{
	element *temp = S->sentinel->next;
	element *succ = MAXIMUM(S);

	if (x == succ)
	{
		return S->sentinel;
	}
	while (temp != S->sentinel)
	{
		if (temp->key > x->key && succ->key > temp->key)
		{
			succ = temp;
		}
		temp = temp->next;
	}
	return succ;
}

element* PREDECESSOR(list* S, element *x)
{
	element *temp = S->sentinel->next;
	element *pred = MINIMUM(S);

	if (x == pred)
	{
		return S->sentinel;
	}
	while (temp != S->sentinel)
	{
		if (temp->key < x->key && pred->key < temp->key)
		{
			pred = temp;
		}
		temp = temp->next;
	}
	return pred;
}

void INSERT(list *S, element *x)
{
	x->next = S->sentinel->next;
	S->sentinel->next->prev = x;
	S->sentinel->next = x;
	x->prev = S->sentinel;
	S->size++;
}

void PUSHBACK(list* S, element *x)
{
	x->prev = S->sentinel->prev;
	S->sentinel->prev->next = x;
	S->sentinel->prev = x;
	x->next = S->sentinel;
	S->size++;

}

element* DELETE(list *S, element *x)
{
	if (x == S->sentinel)
	{
		printf("Canceled\n");
		return S->sentinel;
	}
	else
	{
		x->prev->next = x->next;
		x->next->prev = x->prev;
		S->size--;
		return x;
	}
}

void LIST_PUSH(list *S, element *x)
{
	x->next = S->sentinel->next;
	x->prev = S->sentinel;
	x->next->prev = x;
	S->sentinel->next = x;
	S->size++;
}

element* LIST_POP(list *S)
{
	if (S->sentinel->next == S->sentinel)
	{
		//printf("Underflow error\n");
		return S->sentinel;
	}
	else
	{
		return DELETE(S, S->sentinel->next);
	}
}
void ENQUEUE_LIST(list *Q, element *x)
{
	INSERT(Q, x);
	//printf("Enqueued %d\n", x->key);
}

element* DEQUEUE_LIST(list *Q)
{
	if (Q->sentinel->next == Q->sentinel)
	{
		printf("Underflow error  LIST EMPTY\n");
		return Q->sentinel;
	}
	else
	{
		Q->sentinel->prev = Q->sentinel->prev->prev;
		Q->size--;
		//printf("Dequeued %d\n", Q->sentinel->prev->next->key);
		return Q->sentinel->prev->next;
	}
}

void LINKED_NPOW2(list *S, int k)
{
	for (int i = 0; i < k; i++)
	{
		//Runtime N
		PUSHBACK(S, DELETE(S,S->sentinel->next));
	}
}

void PRINT_LIST(list *S)
{
	element *x = S->sentinel->next;
	while (x != S->sentinel)
	{
		printf("%d", x->key);
		x = x->next;
	}
	printf("\n");
}