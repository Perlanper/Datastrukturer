#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Linkedlist.h"
#include "Graph.h"



graph* NEW_GRAPH(int n)
{
	graph *G = malloc(sizeof(graph));
	G->matrix = malloc(sizeof(vertex)*n);
	G->size = n;

	for (int i = 0; i < G->size; i++)
	{
		G->matrix[i] = malloc(sizeof(vertex));
		G->matrix[i]->ID = i;
		G->matrix[i]->Out_Edge = calloc(n, sizeof(int));
	}
	return G;
}

int GET_NUM_EDGES(graph *G)
{
	int edges = 0;
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (G->matrix[i]->Out_Edge[j] != 0)
			{
				edges++;
			}
		}
	}
	return edges;
}

int GET_NUM_VERTICES(graph *G)
{
	return G->size;
}

list* GET_OUTNEIGHBORS(graph *G, vertex *v)
{
	list * L = NEW_LIST();
	L->sentinel->key = v->ID;
	for (int i = 0; i < G->size; i++)
	{
		if (v->Out_Edge[i] != 0)
		{
			LIST_INSERT(L, NEW_ELEM(i));
		}
	}
	return L;
}

list* GET_INNEIGHBORS(graph *G, vertex *v)
{
	list *L = NEW_LIST();
	L->sentinel->key = v->ID;
	for (int i = 0; i < G->size; i++)
	{
		if (G->matrix[i]->Out_Edge[v->ID] != 0)
		{
			LIST_INSERT(L, NEW_VERTEX_ELEM(G->matrix[i]));
		}
	}
	return L;
}

list* GET_ALLNEIGHBORS(graph *G, vertex *v)
{
	list *L = NEW_LIST();
	for (int i = 0; i < G->size; i++)
	{
		if (G->matrix[i]->Out_Edge[v->ID] != 0)
		{
			LIST_INSERT(L, NEW_VERTEX_ELEM(G->matrix[i]));
		}
	}
	for (int j = 0; j < G->size; j++)
	{
		if (v->Out_Edge[j] != 0 && G->matrix[j]->Out_Edge[v->ID] != 1)
		{
			LIST_INSERT(L, NEW_VERTEX_ELEM(G->matrix[j]));
		}
	}
	return L;
}

int HAS_EDGE(vertex *x, vertex *y)
{
	if (x->Out_Edge[y->ID] != 0)
	{
		return 1;
	}
	if (y->Out_Edge[x->ID] != 0)
	{
		return 1;
	}
	return 0;
}

void ADD_DIRECTED_EDGE(vertex *x, vertex *y)
{
	if (x->Out_Edge[y->ID] != 0)
	{
		return;
	}
	x->Out_Edge[y->ID] = 1;
}
void ADD_UNDIRECTED_EDGE(vertex *x, vertex *y)
{
	x->Out_Edge[y->ID] = 1;
	y->Out_Edge[x->ID] = 1;
}
int RANDOMPERCENT(double sparsity)
{
	double random = rand();
	double percent = random / RAND_MAX;
	if (percent <= sparsity)
	{
		return 1;
	}
	return 0;
}
void DFS(graph *G)
{

	for (int i = 0; i < G->size; i++)
	{
		G->matrix[i]->color = 1;	//Color White
		G->matrix[i]->pred = NULL;		//Predecessor
	}
	G->time = 0;

	for (int i = 0; i < G->size; i++)
	{
		if (G->matrix[i]->color == 1)
		{
			DFS_VISIT(G, G->matrix[i]);
		}
	}

}

void DFS_VISIT(graph *G, vertex *v)
{
	G->time = G->time + 1;
	v->discovery_time = G->time;
	v->color = 2;	//Color Grey

	for (int i = 0; i < G->size; i++)
	{
		if (v->Out_Edge[i] != 0)
		{
			if (G->matrix[i]->color == 1) //If Color is White
			{
				G->matrix[i]->pred = v;
				DFS_VISIT(G, G->matrix[i]);
			}
		}
	}
	v->color == 3; //Color Black
	G->time = G->time + 1;
	v->finnishing_time = G->time;

}

void CREATE_RANDOM_UNEDGE(graph *G, double sparsity)
{
	if (sparsity > 1 || sparsity < 0)
	{
		printf("ERROR SPARSITY NOT VAILD");
		return;
	}
	//srand(time(NULL));
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (RANDOMPERCENT(sparsity) == 1)
			{
				ADD_UNDIRECTED_EDGE(G->matrix[i], G->matrix[j]);
			}
		}
	}
}

void RANDOM_COST_EDGE(vertex * v1, vertex * v2,int edgeCostLowerBound, int edgeCostUpperBound) {
	srand(time(NULL));
	int randomWeight = (rand() % (edgeCostUpperBound - edgeCostLowerBound + 1) + edgeCostLowerBound);

	v1->Out_Edge[v2->ID] = randomWeight;
	
}

void GRAPH_EXERCISE5(graph * G, int low, int max)
{

	int onEdge = 0;

	for (int i = 0; i < G->size; i++) 
	{

		onEdge++;
		if (onEdge != 10) 
		{
			//If there exists a node "to the right"
			RANDOM_COST_EDGE(G->matrix[i], G->matrix[i + 1], low, max);
			RANDOM_COST_EDGE(G->matrix[i + 1], G->matrix[i], low, max);

		}
		else {
			onEdge = 0;
		}


		if (i < 90) 
		{
			//If there exists a node "below"
			RANDOM_COST_EDGE(G->matrix[i], G->matrix[i + 10], low, max);
			RANDOM_COST_EDGE(G->matrix[i + 10], G->matrix[i], low, max);

		}

	}


	//Now we will remove the elements to form the graph on the Exersize 5.
	DELETE_GRAPH_NODES(G, G->matrix[4]);
	DELETE_GRAPH_NODES(G, G->matrix[14]);
	DELETE_GRAPH_NODES(G, G->matrix[24]);
	DELETE_GRAPH_NODES(G, G->matrix[34]);
	DELETE_GRAPH_NODES(G, G->matrix[44]);
	DELETE_GRAPH_NODES(G, G->matrix[45]);
	DELETE_GRAPH_NODES(G, G->matrix[46]);
	DELETE_GRAPH_NODES(G, G->matrix[47]);
	DELETE_GRAPH_NODES(G, G->matrix[48]);
	DELETE_GRAPH_NODES(G, G->matrix[54]);
	DELETE_GRAPH_NODES(G, G->matrix[65]);
	DELETE_GRAPH_NODES(G, G->matrix[75]);
	DELETE_GRAPH_NODES(G, G->matrix[81]);
	DELETE_GRAPH_NODES(G, G->matrix[82]);
	DELETE_GRAPH_NODES(G, G->matrix[83]);
	DELETE_GRAPH_NODES(G, G->matrix[84]);

}


void DELETE_GRAPH_NODES(graph *G, vertex *v)
{

	if (v->ID > 10) 
	{ //If it's NOT on the "top row"
		G->matrix[v->ID - 10]->Out_Edge[v->ID] = 0; //Remove the edge from the top to the"v node".
	}

	if (v->ID < 90) 
	{ //If it's NOT on the "last row"
		G->matrix[v->ID + 10]->Out_Edge[v->ID] = 0;
	}

	//Delete left and right edges to the node
	G->matrix[v->ID + 1]->Out_Edge[v->ID] = 0;
	G->matrix[v->ID - 1]->Out_Edge[v->ID] = 0;

	for (int i = 0; i < G->size; i++) 
	{
		G->matrix[v->ID]->Out_Edge[i] = 0;
	}
	

}
