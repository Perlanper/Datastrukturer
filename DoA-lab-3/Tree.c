#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

tree* NEW_TREE()
{
	tree *T = malloc(sizeof(tree));
	T->root = NULL;
	return T;
}

int TREE_EMPTY(tree *T)
{
	if (T->root == NULL)
	{
		return 1;
	}
	return 0;
}

element* NEW_ELEM(int k)
{
	element *E = malloc(sizeof(element));
	E->key = k;
	E->parent = NULL;
	E->right = NULL;
	E->left = NULL;
	return E;
}

void TREE_INSERT(tree *T, element *z)
{
	element *y = NULL;
	element *x = T->root;
	while (x != NULL)
	{
		y = x;
		if (z->key < y->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL)
	{
		T->root = z;
	}
	else if (z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
}

element* TREE_MINIMUM(element *x)
{
	while (x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

element* TREE_MAXIMUM(element *x)
{
	while (x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

element* TREE_SUCCESSOR(element *x)
{
	if (x->right != NULL)
	{
		return TREE_MAXIMUM(x->right);
	}
	element *y = x->parent;
	while (y != NULL && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

element* TREE_PREDECESSOR(element *x)
{
	if (x->left != NULL)
	{
		return TREE_MAXIMUM(x->left);
	}
	element *y = x->parent;
	while (y != NULL && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

element* TREE_SEARCH(element *x, int k)
{
	while (x != NULL && k != x->key)
	{
		if (k < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

void TRANSPLANT(tree *T, element *u, element * v)
{
	if (u->parent == NULL)
	{
		T->root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	if (v != NULL)
	{
		v->parent = u->parent;
	}
}

element* TREE_DELETE(tree *T, element *z)
{
	if (z->left == NULL)
	{
		TRANSPLANT(T, z, z->right);
	}
	else if (z->right == NULL)
	{
		TRANSPLANT(T, z, z->left);
	}
	else
	{
		element *y = TREE_MINIMUM(z->right);
		if (y->parent != z)
		{
			TRANSPLANT(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		TRANSPLANT(T, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	return z;
}

void INORDER_TREE_WALK(element *x)
{
	if (x != NULL)
	{
		INORDER_TREE_WALK(x->left);
		printf("%d\n", x->key);
		INORDER_TREE_WALK(x->right);
	}
}