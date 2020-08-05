#include "binary_trees.h"

/**
 * binary_tree_node -  function that creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value node
 * Return: Always 0 (Success)
 */

heap_t *heap_insert(heap_t **root, int value)
{
	/* int full; */

	/* full = binary_tree_is_full(*root); */
	if (*root == NULL)
		return (binary_tree_node(*root, value));

	if ((*root)->n < value)
		binary_tree_insert_left((*root)->left, value);
	/* else */
	/* if (full == 0) */
	/* { */
	/*   /\* 	if (*root->left == NULL) *\/ */
	/*   /\* binary_tree_insert *\/ */
	/* } */
	return (*root);
}

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left) && (tree->right))
	{
		if (binary_tree_is_full(tree->left) &&
		    binary_tree_is_full(tree->right))
		{
			return (1);
		}
	}
	return (0);
}


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;
	binary_tree_t *tmp = NULL;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (parent->left == NULL)
	{
		parent->left = node;
	}
	else
	{
		tmp = parent->left;
		tmp->parent = node;
		parent->left = node;
		node->left = tmp;
	}
	return (node);
}

/**
 * binary_tree_insert_right - function that inserts a node as the right-child
 *
 * @parent: node parent
 * @value: value node
 *
 * Return: binary tree
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;
	binary_tree_t *tmp = NULL;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (parent->right == NULL)
	{
		parent->right = node;
	}
	else
	{
		tmp = parent->right;
		tmp->parent = node;
		parent->right = node;
		node->right = tmp;
	}
	return (node);
}
