#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Linkedlist2.h"
#include "queue.h"

int main()
{
	//EXERCISE 1
	printf("::EXERCISE 1::\n");
	list *L = NEW_LIST(); // CREATING LIST
	INSERT(L, NEW_ELEM(5)); // INSERTING A ELEMENT

	//--------------INSERT TEST----------------------------------
	int returnvalue = L->sentinel->next->key;
	int expvalue = 5;
	if (returnvalue != expvalue)
	{
		printf("INSERT TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}

	//---------------SEARCH TEST----------------------------------
	INSERT(L, NEW_ELEM(6));
	INSERT(L, NEW_ELEM(7));

	returnvalue = SEARCH_LIST(L, 6)->key;
	expvalue = 6;
	if (returnvalue != expvalue)
	{
		printf("SEARCH TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}

	//--------------DELETE TEST-----------------------------------
	returnvalue = DELETE(L, SEARCH_LIST(L, 7))->key;
	expvalue = 7;
	if (returnvalue != expvalue)
	{
		printf("DELETE TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}

	//--------------MINIMUM TEST----------------------------------
	INSERT(L, NEW_ELEM(1));
	INSERT(L, NEW_ELEM(10));
	INSERT(L, NEW_ELEM(3));
	INSERT(L, NEW_ELEM(9));

	returnvalue = MINIMUM(L)->key;
	expvalue = 1;
	if (returnvalue != expvalue)
	{
		printf("MINIMUM TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}

	//-------------MAXIMUM TEST-----------------------------------
	returnvalue = MAXIMUM(L)->key;
	expvalue = 10;
	if (returnvalue != expvalue)
	{
		printf("MINIMUM TEST TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}

	//-------------PREDECESSOR TEST-------------------------------
	returnvalue = PREDECESSOR(L, SEARCH_LIST(L,9))->key;
	expvalue = 6;
	if (returnvalue != expvalue)
	{
		printf("PREDECESSSOR TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}

	//-------------SUCCESSOR TEST---------------------------------
	returnvalue = SUCCESSOR(L, SEARCH_LIST(L, 3))->key;
	expvalue = 5;
	if (returnvalue != expvalue)
	{
		printf("SUCCESSOR TEST FAILED! expected:%d returned: %d\n", expvalue, returnvalue);
	}
	printf("-------------------------------------\n");

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//EXERCISE 2 TESTS
	printf("::EXERCISE 2::\n");
	list *list1 = NEW_LIST();
	

	LIST_POP(list1); //UNDERFLOW TEST
	
	LIST_PUSH(list1, NEW_ELEM(2)); //ADDING ELEMENTS
	LIST_PUSH(list1, NEW_ELEM(3));
	LIST_PUSH(list1, NEW_ELEM(4));

	returnvalue = LIST_POP(list1)->key;
	expvalue = 4;
	if (returnvalue != expvalue) //TESTING POP FUNCTION
	{
		printf("POP TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}
	returnvalue = LIST_POP(list1)->key;
	expvalue = 3;
	if (returnvalue != expvalue)
	{
		printf("POP TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}
	returnvalue = LIST_POP(list1)->key;
	expvalue = 2;
	if (returnvalue != expvalue)
	{
		printf("POP TEST FAILED expected:%d returned: %d", expvalue, returnvalue);
	}
	printf("------------------------------------\n");
	

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//EXERCISE 3 TESTS
	printf("::EXERCISE 3::\n");
	intArrej *arr = NEW_ARRAY(4);
	ARRAY_POP(arr); // UNDERFLOW TEST

	ARRAY_PUSH(arr, 4); //ADDING ELEMENTS 
	ARRAY_PUSH(arr, 5);
	ARRAY_PUSH(arr, 6);
	ARRAY_PUSH(arr, 7);

	returnvalue = ARRAY_POP(arr);
	expvalue = 7;
	if (returnvalue != expvalue) //TESTING POP FUNCTION
	{
		printf("POP TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}
	returnvalue = ARRAY_POP(arr);
	expvalue = 6;
	if (returnvalue != expvalue)
	{
		printf("POP TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}

	ARRAY_PUSH(arr, 8); // PUSH OK
	ARRAY_PUSH(arr, 9); // PUSH OK
	ARRAY_PUSH(arr, 10); // OVERFLOW PUSH
	printf("------------------------------------\n");


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	//EXERCISE 4
	printf("::EXERCISE 4::\n");
	list *list3 = NEW_LIST();

	DEQUEUE_LIST(list3); //UNDERFLOW TEST

	ENQUEUE_LIST(list3, NEW_ELEM(1)); // ADDING ELEMENTS
	ENQUEUE_LIST(list3, NEW_ELEM(2));
	ENQUEUE_LIST(list3, NEW_ELEM(3));
	ENQUEUE_LIST(list3, NEW_ELEM(4));

	returnvalue = DEQUEUE_LIST(list3)->key;
	expvalue = 1;
	if (returnvalue != expvalue) // TESTING DEQUEUE FUNCTION
	{
		printf("DEQUEUE TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}
	returnvalue = DEQUEUE_LIST(list3)->key;
	expvalue = 2;
	if (returnvalue != expvalue)
	{
		printf("DEQUEUE TEST FAILED expected:%d returned: %d", expvalue, returnvalue);
	}
	printf("------------------------------------\n");
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	//EXERCISE 5
	printf("::EXERCISE 5::\n");
	arrayque *arr2 = NEW_QUEUE(4);
	DEQUEUE_ARRAY(arr2); //UNDERFLOW TEST

	ENQUEUE_ARRAY(arr2, 5); //ADDING ELEMENTS
	ENQUEUE_ARRAY(arr2, 6);
	ENQUEUE_ARRAY(arr2, 7);
	ENQUEUE_ARRAY(arr2, 8);

	returnvalue = DEQUEUE_ARRAY(arr2);
	expvalue = 5;
	if (returnvalue != expvalue) //TESTING DEQUEUE FUNCTION
	{
		printf("DEQUEUE TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}

	returnvalue = DEQUEUE_ARRAY(arr2);
	expvalue = 6;
	if (returnvalue != expvalue)
	{
		printf("DEQUEUE TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}

	returnvalue = DEQUEUE_ARRAY(arr2);
	expvalue = 7;
	if (returnvalue != expvalue)
	{
		printf("DEQUEUE TEST FAILED expected:%d returned: %d\n", expvalue, returnvalue);
	}

	ENQUEUE_ARRAY(arr2, 1); // ENQUEUE OK
	ENQUEUE_ARRAY(arr2, 2); // ENQUEUE OK
	ENQUEUE_ARRAY(arr2, 3); // ENQUEUE OK
	ENQUEUE_ARRAY(arr2, 4); // OVERFLOW ENQUEUE

	printf("------------------------------------\n");

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//EXERCISE 11
	printf("::EXERCISE 11::\n");
	printf("*Bitshifting-LINKED LIST*\n");
	list *list5 = NEW_LIST();

	INSERT(list5, NEW_ELEM(0));
	INSERT(list5, NEW_ELEM(1));
	INSERT(list5, NEW_ELEM(0));
	INSERT(list5, NEW_ELEM(1));
	INSERT(list5, NEW_ELEM(1));
	INSERT(list5, NEW_ELEM(1));
	INSERT(list5, NEW_ELEM(0));
	INSERT(list5, NEW_ELEM(0));
	printf("BEFORE:  ");
	PRINT_LIST(list5);
	LINKED_NPOW2(list5, 2);
	printf("AFTER:   ");
	PRINT_LIST(list5);

//--------------------------------------------------------------------------------------------------------------------------------------------------

	printf("--------------------------------------\n");
	printf("*Bitshifting-ARRAY*\n");
	intArrej *arr3 = NEW_ARRAY(8);

	ARRAY_PUSH(arr3, 0);
	ARRAY_PUSH(arr3, 1);
	ARRAY_PUSH(arr3, 0);
	ARRAY_PUSH(arr3, 1);
	ARRAY_PUSH(arr3, 1);
	ARRAY_PUSH(arr3, 1);
	ARRAY_PUSH(arr3, 0);
	ARRAY_PUSH(arr3, 0);
	printf("BEFORE:  ");
	PRINT_ASTACK(arr3);
	ARRAY_NPOW2(arr3, 2);
	printf("AFTER:   ");
	PRINT_ASTACK(arr3);

	system("pause");

}