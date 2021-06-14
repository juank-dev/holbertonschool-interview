#include "binary_trees.h"
/**
 * tree_size - returns the size of the tree
 * @root: pointer to the head
 * Return: size of the tree
 **/
int tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + tree_size(root->left) + tree_size(root->right));
}
/**
 * swap_nodes - swaps nodes values
 * @a: node a
 * @b: node b
 * Return: the first given node
 **/
heap_t *swap_nodes(heap_t *a, heap_t *b)
{
	a->n = a->n * b->n;
	b->n = a->n / b->n;
	a->n = a->n / b->n;
	return (a);
}
/**
 * last_Node - returns the last node
 * @root: pointer to the root node
 * @size: size of the tree
 * Return: the found node ptr
 **/
heap_t *last_Node(heap_t *root, int size)
{
	int b_idx = 0;
	int mask = 0;

	for (; 1 << (b_idx + 1) <= size; b_idx++)
		;
	for (b_idx--; b_idx >= 0; b_idx--)
	{
		mask = 1 << b_idx;
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heapify - converts the tree into a max heap tree
 * @root: pointer to the root node
 */
void heapify(heap_t *root)
{
	heap_t *max = NULL;
	int first = 0;

	while (max || !first)
	{
		max = NULL;
		first = 1;
		if (root->left && root->left->n > root->n)
			max = root->left;
		if (root->right && root->right->n > root->n &&
			(max && root->right->n > max->n))
			max = root->right;
		if (max)
			root = swap_nodes(max, root);
	}
}
/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root:  is a double pointer to the root node of the heap
 * Return: the value stored in the root node, otherwise 0
 */
int heap_extract(heap_t **root)
{
	int max = (*root)->n;
	int size = tree_size(*root);
	heap_t *last_node = last_Node(*root, size);

	swap_nodes(last_node, *root);
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);
	heapify(*root);
	return (max);
}
