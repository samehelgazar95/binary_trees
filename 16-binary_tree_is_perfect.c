#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * the height is the number of the vertices
 * @tree: the tree root
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left > right ? left : right);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * @tree: the tree root
 * Return: the nodes counts
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * tree is perfect when:
 * number of nodes = 2^height - 1
 * @tree: the root
 * Return: the balance factor
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h = (int)binary_tree_height(tree);
	int nodes = (int)binary_tree_nodes(tree);
	int power = 1, i;

	for (i = 0; i < h; i++)
		power *= 2;

	if (power - 1 == nodes)
		return (1);
	else
		return (0);
}
