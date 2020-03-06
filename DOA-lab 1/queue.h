typedef struct arrayqueue_t
{
	int head, tail, legnth, size;
	int *array;
}arrayque;

arrayque* NEW_QUEUE(int x);
int QUEUE_EMPTY(arrayque *Q);
int QUEUE_FULL(arrayque *Q);
void ENQUEUE_ARRAY(arrayque *Q, int x);
int DEQUEUE_ARRAY(arrayque *Q);
void PRINT_QUEUE(arrayque * arr);



