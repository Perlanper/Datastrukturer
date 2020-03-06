vertex *EXTRACT_MIN(vertexlist *L);
void VERTEX_LIST_ADD(vertexlist *Q, vertex *v);
void INIT_SINGLE_SOURCE(graph *G, vertex *s);
void RELAX(vertex *u, vertex *v, int weight);
void DIJKSTRA(graph *G, vertex *s);
void PRINT_SHORTEST_PATH(vertex *source, vertex *from);