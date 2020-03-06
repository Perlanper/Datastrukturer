#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


//QUEUE_FUNCTIONS FOR ARRAY

arrayque* NEW_QUEUE(int x)
{
	arrayque *Q = malloc(sizeof(arrayque));
	Q->legnth = x;
	Q->head = Q->size = 0;
	Q->tail = -1;
	Q->array = calloc(x, sizeof(int));
	return Q;
}

int QUEUE_EMPTY(arrayque *Q)
{
	if (Q->legnth == 0)
		return 1;
	return 0;
}
int QUEUE_FULL(arrayque *Q)
{
	if (Q->size == Q->legnth)
		return 1;
	return 0;
}

void ENQUEUE_ARRAY(arrayque *Q, int x)
{
	if (Q->size == Q->legnth)
	{
		printf("Overflow error ARRAY FULL\n");
		return;
	}
	else
	{
		Q->size++;
		Q->tail++;
		if (Q->tail == Q->legnth)
		{
			Q->tail = 0;
		}
		Q->array[Q->tail] = x;
		//printf("QUEUED %d\n", x);
	}
}

int DEQUEUE_ARRAY(arrayque *Q)
{
	if (Q->size == 0)
	{
		printf("Underflow error ARRAY EMPTY\n");
		return Q->size;
	}
	int x = Q->array[Q->head];
	Q->size--;
	Q->head++;
	//printf("DEQUEUED %d\n", x);
	if (Q->head == Q->legnth)
	{
		Q->head = 0;
	}
	return x;
}

void PRINT_QUEUE(arrayque * arr)
{
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d\n", arr[i]);
	}
}