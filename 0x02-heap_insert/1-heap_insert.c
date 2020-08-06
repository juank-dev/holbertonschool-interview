#include "binary_trees.h"

/**
 * binary_tree_node -  function that creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value node
 * Return: Always 0 (Success)
 */

heap_t *heap_insert(heap_t **root, int value)
{
	int full;

	full = binary_tree_is_full(*root);
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}

	if (full == 1)
		if (value > (*root)->n)
			*root = binary_tree_insert_left(*root, value);
		else
			return (binary_tree_insert_left(*root, value));
	else
		if (value > (*root)->n)
			*root = binary_tree_insert_right(*root, value);
		else
			return (binary_tree_insert_right(*root, value));
	return (*root);
}


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;
	/* binary_tree_t *tmp = NULL; */

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	/* tmp = node; */
	if (value > parent->n)
	{
		if (parent->left == NULL)
		{
			node->left = parent;
			node->parent = parent->parent;
			node->right = parent->right;
			parent->parent = node;
			parent->left = NULL;
			parent->right = NULL;
		}
		else
		{
			binary_tree_insert_left(parent->left, value);
		}
	}
	else
	{
		if (parent->left == NULL)
			parent->left = node;
		else
			binary_tree_insert_left(parent->left, value);
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

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (value > parent->n)
	{
		if (parent->right == NULL)
		{
			node->right = parent;
			node->parent = parent->parent;
			node->left = parent->left;
			parent->parent = node;
			parent->left = NULL;
			parent->right = NULL;
		}
		else
		{
			binary_tree_insert_right(parent->right, value);
		}
	}
	else
	{
		if (parent->right == NULL)
			parent->right = node;
		else
			binary_tree_insert_right(parent->right, value);
	}
	return (node);
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
