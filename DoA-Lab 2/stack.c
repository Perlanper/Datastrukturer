#include "stack.h"
#include "Linkedlist2.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//FUNCTIONS FOR CREATING ARRAY

intArrej* NEW_ARRAY(int x)
{
	intArrej *arrej = malloc(sizeof(intArrej));
	arrej->size = x;
	arrej->data = calloc(x, sizeof(int));
	arrej->beg = (arrej->data - 1);
	return arrej;
}

//STACK_FUNCTIONS FOR ARRAY

int ARRAY_EMPTY(intArrej * S)
{
	if (S->beg == (S->data - 1))
		return 1;
	return 0;
}

void ARRAY_PUSH(intArrej *S, int x)
{
	if (S->beg == (S->data - 1))
	{
		S->beg = S->data;
		*S->beg = x;
		//printf("number %d pushed\n", x);
	}
	 else if (S->beg != (S->data + S->size - 1))
	{
		 S->beg = S->beg + 1;
		*S->beg = x;
		//printf("number %d pushed\n", x);
	}
	else
	{
		printf("Overflow error ARRAY FULL\n");
	}
}

int ARRAY_POP(intArrej *S)
{
	if (S->beg == (S->data - 1))
	{
		//printf("Underflow error ARRAY EMPTY\n");
		return S->size;
	}
	else
	{
		S->beg--;
		//printf("number %d popped\n", *(S->beg + 1));
		return *(S->beg + 1);
	}

}
void PRINT_ASTACK(intArrej * arr)
{
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d", arr->data[i]);
	}
	printf("\n");
}


void ARRAY_NPOW2(intArrej *arr, int k)
{
	//Runtime N^2
	for (int i = 0; i < k; i++)
	{ //Repeat k times.
		int x = arr->data[0];
		for (int j = 0; j < 7; j++)
		{
			arr->data[j] = arr->data[j + 1];
		}
		arr->data[7] = x;
	}
}