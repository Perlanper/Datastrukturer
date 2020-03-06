#include <stdio.h>
#include <stdlib.h>

#include "graph2.h"
#include "Dijkstra.h"

int main()
{
// EXERSICE 1----------------------------------------------------------------------------------------------------------------------------------------
//VERTICES TEST	
	graph *graph1 = NEW_GRAPH(10);
	int exp_value = 10;

	if (GET_NUM_VERTICES(graph1) != exp_value)
	{
		printf("VERTEX TEST FAILED! EXPECTED = %d, RETURN VALUE = %d\n",exp_value, GET_NUM_VERTICES(graph1));
	}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//EDGES TEST
	exp_value = 0;
	int return_value = GET_NUM_EDGES(graph1);
	if (return_value != exp_value)
	{
		printf("EDGE TEST #1 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ADDING EGDES TEST
	ADD_UNDIRECTED_EDGE(graph1->matrix[0], graph1->matrix[1]); // 2 edges
	ADD_UNDIRECTED_EDGE(graph1->matrix[0], graph1->matrix[8]); // 2 edges
	ADD_DIRECTED_EDGE(graph1->matrix[1], graph1->matrix[9]);   // 1 edge
	ADD_DIRECTED_EDGE(graph1->matrix[1], graph1->matrix[2]);   // 1 egde
	ADD_UNDIRECTED_EDGE(graph1->matrix[2], graph1->matrix[7]); // 2 edges
	ADD_UNDIRECTED_EDGE(graph1->matrix[2], graph1->matrix[3]); // 2 edges
	ADD_DIRECTED_EDGE(graph1->matrix[3], graph1->matrix[4]);   // 1 edge
	ADD_DIRECTED_EDGE(graph1->matrix[3], graph1->matrix[9]);   // 1 edge
	ADD_DIRECTED_EDGE(graph1->matrix[4], graph1->matrix[6]);   // 1 edge
	ADD_UNDIRECTED_EDGE(graph1->matrix[4], graph1->matrix[5]); // 2 edges
	ADD_DIRECTED_EDGE(graph1->matrix[5], graph1->matrix[2]);   // 1 edge
	ADD_DIRECTED_EDGE(graph1->matrix[7], graph1->matrix[8]);   // 1 edge
															//------------- total 17 edges
	exp_value = 17;
	return_value = GET_NUM_EDGES(graph1);
	if (return_value != exp_value)
	{
		printf("EDGE TEST #2 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//OUT NEIGHBOURS TEST
	exp_value = 2;
	return_value = GET_OUT_NEIGHBOURS(graph1, graph1->matrix[0])->size;
	if (return_value != exp_value)
	{
		printf("OUT_NEIGHBOR TEST #1 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 2;
	return_value = GET_OUT_NEIGHBOURS(graph1, graph1->matrix[5])->size;
	if (return_value != exp_value)
	{
		printf("OUT_NEIGHBOR TEST #2 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 3;
	return_value = GET_OUT_NEIGHBOURS(graph1, graph1->matrix[3])->size;
	if (return_value != exp_value)
	{
		printf("OUT_NEIGHBOR TEST #3 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 0;
	return_value = GET_OUT_NEIGHBOURS(graph1, graph1->matrix[6])->size;
	if (return_value != exp_value)
	{
		printf("OUT_NEIGHBOR TEST #4 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//IN NEIGHBOURS TEST
	exp_value = 2;
	return_value = GET_IN_NEIGHBOURS(graph1, graph1->matrix[9])->size;
	if (return_value != exp_value)
	{
		printf("IN_NEIGHBOUR TEST #1 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 4;
	return_value = GET_IN_NEIGHBOURS(graph1, graph1->matrix[2])->size;
	if (return_value != exp_value)
	{
		printf("IN_NEIGHBOUR TEST #2 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 1;
	return_value = GET_IN_NEIGHBOURS(graph1, graph1->matrix[6])->size;
	if (return_value != exp_value)
	{
		printf("IN_NEIGHBOUR TEST #3 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 2;
	return_value = GET_IN_NEIGHBOURS(graph1, graph1->matrix[8])->size;
	if (return_value != exp_value)
	{
		printf("IN_NEIGHBOUR TEST #4 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//ALL NEIGHBOURS TEST

	exp_value = 2;
	return_value = GET_ALLNEIGHBOURS(graph1, graph1->matrix[5])->size;
	if (return_value != exp_value)
	{
		printf("ALL_NEIGHBOUR TEST #1 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 4;
	return_value = GET_ALLNEIGHBOURS(graph1, graph1->matrix[2])->size;
	if (return_value != exp_value)
	{
		printf("ALL_NEIGHBOUR TEST #2 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 3;
	return_value = GET_ALLNEIGHBOURS(graph1, graph1->matrix[3])->size;
	if (return_value != exp_value)
	{
		printf("ALL_NEIGHBOUR TEST #3 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 1;
	return_value = GET_ALLNEIGHBOURS(graph1, graph1->matrix[6])->size;
	if (return_value != exp_value)
	{
		printf("ALL_NEIGHBOUR TEST #4 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//EXERCISE 2---------------------------------------------------------------------------------------------------------------------------------------------
	graph *randomgraph1 = NEW_GRAPH(10);
	graph *randomgraph2 = NEW_GRAPH(10);
	graph *randomgraph3 = NEW_GRAPH(10);

	CREATE_RANDOM_UNEDGE(randomgraph1, 0); //no edges
	CREATE_RANDOM_UNEDGE(randomgraph2, 0,5); // some edges
	CREATE_RANDOM_UNEDGE(randomgraph3, 1);  //  all edges

	exp_value = 0;
	return_value = GET_NUM_EDGES(randomgraph1);
	if (return_value != exp_value)
	{
		printf("RANDOM EDGE TEST #1 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}


	return_value = GET_NUM_EDGES(randomgraph2);
	if (return_value > 0 && return_value < 100)
	{
		printf("RANDOM EDGE TEST #2 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}

	exp_value = 100;
	return_value = GET_NUM_EDGES(randomgraph3);
	if (return_value != exp_value)
	{
		printf("RANDOM EDGE TEST #3 FAILED! EXPECTED = %d, RETURN VALUE = %d\n", exp_value, return_value);
	}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//EXERCISE 4----------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("::EXERCISE 4::\n");
	graph *DFSgraph = NEW_GRAPH(9);

	ADD_DIRECTED_EDGE(DFSgraph->matrix[0], DFSgraph->matrix[1]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[0], DFSgraph->matrix[6]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[1], DFSgraph->matrix[2]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[1], DFSgraph->matrix[6]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[2], DFSgraph->matrix[3]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[4], DFSgraph->matrix[2]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[4], DFSgraph->matrix[5]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[5], DFSgraph->matrix[3]);
	ADD_DIRECTED_EDGE(DFSgraph->matrix[7], DFSgraph->matrix[6]);

	DFS(DFSgraph);

	for (int i = 0; i < DFSgraph->size; i++)
	{
		printf("Vertex %d: Discovery Time: %d , Finnishing Time: %d \n", i, DFSgraph->matrix[i]->discovery_time, DFSgraph->matrix[i]->finnishing_time);
	}
	printf("-------------------------------------------------------------\n");
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//EXERCISE 5------------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("::EXERCISE 5::\n");
	graph *graph5 = NEW_GRAPH(100);
	GRAPH_EXERCISE5(graph5, 1, 10);
	DIJKSTRA(graph5, graph5->matrix[0]);
	PRINT_SHORTEST_PATH(graph5->matrix[0], graph5->matrix[35]);  // between (1,1) and (6,4)
	PRINT_SHORTEST_PATH(graph5->matrix[0], graph5->matrix[92]);  // between (1,1) and (3,10)
	system("pause");
}