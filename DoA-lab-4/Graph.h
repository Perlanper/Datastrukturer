#pragma once

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

graph* NEW_GRAPH(int n);
int GET_NUM_EDGES(graph *G);
int GET_NUM_VERTICES(graph *G);
struct list_t* GET_OUTNEIGHBORS(graph *G, vertex *v);
struct list_t* GET_INNEIGHBORS(graph *G, vertex *v);
int HAS_EDGE(vertex *x, vertex *y);
void ADD_DIRECTED_EDGE(vertex *x, vertex *y);
void ADD_UNDIRECTED_EDGE(vertex *x, vertex *y);
int RANDOMPERCENT(double sparsity);
void DFS(graph *G);
void DFS_VISIT(graph *G, vertex *v);
void CREATE_RANDOM_UNEDGE(graph *G, double sparsity);
void RANDOM_COST_EDGE(vertex * v1, vertex * v2, int edgeCostLowerBound, int edgeCostUpperBound);
void GRAPH_EXERCISE5(graph * G, int low, int max);
void DELETE_GRAPH_CONNECTIONS(graph * G, vertex * v);
