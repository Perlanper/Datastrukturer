typedef struct arrej_t
{
	int size;
	int *data;
	int *beg;
}intArrej;

intArrej* NEW_ARRAY(int x);
int ARRAY_EMPTY(intArrej * S);
void ARRAY_PUSH(intArrej *S, int x);
int ARRAY_POP(intArrej *S);
void PRINT_ASTACK(intArrej * arr);
void ARRAY_NPOW2(intArrej *arr, int k);

