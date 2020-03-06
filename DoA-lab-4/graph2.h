#pragma once

typedef struct element_t
{
	struct vertex_t *vtx;
	struct element_t *next;
	struct element_t *prev;
}element;

typedef struct list_t
{
	element *sentinel;
	int size;
}list;

typedef struct vertex_t
{
	int ID;
	int *Out_Edge;
	int color;
	int discovery_time;
	int finnishing_time;
	struct vertex_t *pred;
	struct vertex_t *next;
	struct vertex_t *prev;
}vertex;

typedef struct graph_t
{
	vertex **matrix;
	int time;
	int size;
}graph;

typedef struct vertexlist_t
{
	struct vertex_t *sentinel;
}vertexlist;

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

list* NEW_LIST();
void LIST_INSERT(list *L, element *x);
element* NEW_VERTEX_ELEM(vertex *v);
graph* NEW_GRAPH(int n);
int GET_NUM_EDGES(graph *G);
int GET_NUM_VERTICES(graph *G);
list* GET_IN_NEIGHBOURS(graph *G, vertex *v);
list* GET_OUT_NEIGHBOURS(graph *G, vertex *v);
list* GET_ALLNEIGHBOURS(graph *G, vertex *v);
int HAS_EDGE(vertex *x, vertex *y);
void ADD_DIRECTED_EDGE(vertex *x, vertex *y);
void ADD_UNDIRECTED_EDGE(vertex *x, vertex *y);
int RANDOMPERCENT(double sparsity);
void DFS(graph *G);
void DFS_VISIT(graph *G, vertex *v);
void CREATE_RANDOM_UNEDGE(graph *G, double sparsity);
void RANDOM_COST_EDGE(vertex *v1, vertex *v2, int edgeLowerBound, int edgeUpperBound);
void GRAPH_EXERCISE5(graph * G, int low, int max);
void DELETE_GRAPH_CONNECTIONS(graph *G, vertex *v);