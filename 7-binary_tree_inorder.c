#include "binary_trees.h"

/**
 * binary_tree_inorder - in-order traversal
 *
 * @tree: the root tree
 * @func: the printing function
 * Return: Nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
