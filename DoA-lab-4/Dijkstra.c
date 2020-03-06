#include "Graph.h"
#include "Dijkstra.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


vertexlist * NEW_VERTEX_LIST()
{
	vertexlist *S = malloc(sizeof(vertexlist));
	S->sentinel = malloc(sizeof(vertex));
	S->sentinel->next = S->sentinel;
	S->sentinel->prev = S->sentinel;

	return S;

}

void VERTEX_LIST_ADD(vertexlist *Q, vertex *v)
{
	v->prev = Q->sentinel->prev;
	v->next = Q->sentinel;

	Q->sentinel->prev->next = v;
	Q->sentinel->prev = v;

}



vertex *EXTRACT_MIN(vertexlist *L)
{
	vertex *temp = L->sentinel->next;
	vertex *min = temp;

	while (temp != L->sentinel)
	{
		if (temp->discovery_time < min->discovery_time)
		{
			min = temp;
		}
		temp = temp->next;

	}
	min->prev->next = min->next;
	min->next->prev = min->prev;
	min->next = NULL;
	min->prev = NULL;
	return min;
}


void INIT_SINGLE_SOURCE(graph *G, vertex *s)
{
	for (int i = 0; i < G->size; i++)
	{
		G->matrix[i]->discovery_time = 30000;
		G->matrix[i]->pred = NULL;
	}
	s->discovery_time = 0;

}

void RELAX(vertex *u, vertex *v, int weight) 
{
	if (v->discovery_time > u->discovery_time + weight)
	{
		v->discovery_time = u->discovery_time + weight;
		v->pred = u;
	}
}

void DIJKSTRA(graph *G, vertex *s)
{
	INIT_SINGLE_SOURCE(G, s);
	vertexlist *S = NEW_VERTEX_LIST();
	vertex *u;

	vertexlist *Q = NEW_VERTEX_LIST();
	for (int i = 0; i < G->size; i++) 
	{
		VERTEX_LIST_ADD(Q, G->matrix[i]);
	}

	while (Q->sentinel->next != Q->sentinel->prev) //while Q != 0
	{ 
		u = EXTRACT_MIN(Q);
		VERTEX_LIST_ADD(S, u);

		for (int j = 0; j < G->size; j++) 
		{
			if (u->Out_Edge[j] != 0) 
			{

				RELAX(u, G->matrix[j], u->Out_Edge[j]);
			}
		}
	}
}


void PRINT_SHORTEST_PATH(vertex *source, vertex *destination)
{
	vertex *temp = destination;

	printf("\nShortest path between Vertex ID: %d and Vertex ID: %d is:\n", source->ID, destination->ID);
	while (temp != source)
	{
		printf("Vertex ID: %d\n", temp->ID);
		temp = temp->pred;
	}
	printf("Vertex ID: %d\n", source->ID);
}

