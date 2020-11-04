#include "binary_trees.h"

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 *
 * @array: Array Integer for sort to AVL
 * @size: size of Array
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (array == NULL)
		return (NULL);
	tree = search_avl(array, 0, size - 1, NULL);
	return (tree);
}

/**
 * search_avl - function that validate and sort the tree
 *
 * @array: Array Integer for sort to AVL
 * @first: Start of array
 * @last: End of array
 * @node: node parent
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *search_avl(int *array, int first, int last, avl_t *node)
{
	int half;
	avl_t *new_node;

	if (first > last)
		return (NULL);
	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);
	half = (first + last) / 2;
	new_node->n = array[half];
	new_node->parent = node;
	new_node->left = search_avl(array, first, half - 1, new_node);
	new_node->right = search_avl(array, half + 1, last, new_node);
	return (new_node);
}
