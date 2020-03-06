#pragma once
typedef struct element_t
{
	int key;
	struct element_t *right;
	struct element_t *left;
	struct element_t *parent;
}element;

typedef struct tree_t
{
	element *root;
}tree;

tree* NEW_TREE();
void TREE_INSERT(tree *T, element *z);
element* NEW_ELEM(int k);
int TREE_EMPTY(tree *T);
element* TREE_MINIMUM(element *x);
element* TREE_MAXIMUM(element *x);
element* TREE_PREDECESSOR(element *x);
element* TREE_SUCCESSOR(element *x);
element* TREE_SEARCH(element *x, int k);
void TRANSPLANT(tree *T, element *u, element * v);
element* TREE_DELETE(tree *T, element *z);
void INORDER_TREE_WALK(element *x);
