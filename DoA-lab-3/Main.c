#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{

// EXERCISE 2-------------------------------------------------------------------------------------------------------------------------
	tree *tree = NEW_TREE();
	int exp_value = 1;

	int value = TREE_EMPTY(tree);
	if (value != exp_value)
	{
		printf("TREE IS NOT EMPTY, exp_value = %d , value = %d\n", exp_value, value);
	}

	TREE_INSERT(tree, NEW_ELEM(10));
	exp_value = 0;
	if (TREE_EMPTY(tree) != exp_value)
	{
		printf("TREE IS EMPTY, exp_value = %d , value = %d\n", exp_value, TREE_EMPTY(tree));
	}


// EXERCISE 3-------------------------------------------------------------------------------------------------------------------------
	TREE_INSERT(tree, NEW_ELEM(7));
	TREE_INSERT(tree, NEW_ELEM(3));
	TREE_INSERT(tree, NEW_ELEM(6));
	TREE_INSERT(tree, NEW_ELEM(1));
	TREE_INSERT(tree, NEW_ELEM(8));
	TREE_INSERT(tree, NEW_ELEM(9));
	TREE_INSERT(tree, NEW_ELEM(20));
	TREE_INSERT(tree, NEW_ELEM(15));
	TREE_INSERT(tree, NEW_ELEM(100));
	TREE_INSERT(tree, NEW_ELEM(21));
// MINIMUM FUNCTION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	element *mini_elem = TREE_MINIMUM(tree->root);
	exp_value = 1;

	if (mini_elem->key != exp_value)
	{
		printf("MINIMUM TEST FAILED, exp_value = %d, returned value = %d\n", exp_value, mini_elem->key);
	}
// MAXIMUM FUNCTION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	element *maxi_elem = TREE_MAXIMUM(tree->root);
	exp_value = 100;

	if (maxi_elem->key != exp_value)
	{
		printf("MAXIMUM TEST FAILED, exp_value = %d, returned value = %d\n", exp_value, maxi_elem->key);
	}
// SEARCH FUNCTION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	element *search_elem = TREE_SEARCH(tree->root, 6);
	exp_value = 6;

	if (search_elem->key != exp_value)
	{
		printf("SEARCH TEST FAILED, exp_value = %d, returned value = %d\n", exp_value, search_elem->key);
	}
// SUCCESSOR FUNCTION::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	element *successor = TREE_SUCCESSOR(TREE_SEARCH(tree->root, 6));
	exp_value = 7;

	if (successor->key != exp_value)
	{
		printf("SUCCESSOR TEST FAILED, exp_value = %d, returned value = %d\n", exp_value, successor->key);
	}
// EXERSICE 4----------------------------------------------------------------------------------------------------------------------------------
// DELETE_FUNCTION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	exp_value = 8;
	int return_value = TREE_DELETE(tree, TREE_SEARCH(tree->root, 8))->key;
	if (return_value != exp_value)
	{
		printf("DELETE TEST FAILED, exp_value = %d, deleted value = %d\n", exp_value, return_value);
	}
//EXERCISE 5-----------------------------------------------------------------------------------------------------------------------------------
	INORDER_TREE_WALK(tree->root); //WILL PRINT OUT IN CONSOLE


	system("pause");
}