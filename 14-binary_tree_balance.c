#include "binary_trees.h"

/**
 * subtree_height - measures the height of a binary tree
 * the height is the number of the vertices
 * @tree: the tree root
 * Return: the height
 */

int subtree_height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (0);

	left = tree->left ? subtree_height(tree->left) + 1 : 1;
	right = tree->right ? subtree_height(tree->right) + 1 : 1;

	return (left > right ? left : right);
}

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

	l = subtree_height(tree->left);
	r = subtree_height(tree->right);

	return (l - r);
}
