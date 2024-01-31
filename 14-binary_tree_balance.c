#include "binary_trees.h"

/**
 * binary_tree_balance - calc the balnce factor
 * @tree: the root
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l;
	size_t r;

	if (tree == NULL)
		return (0);

	l = tree->left ? (binary_tree_balance(tree->left) + 1) : 0;
	r = tree->right ? (binary_tree_balance(tree->right) + 1) : 0;

	return (l - r);
}
