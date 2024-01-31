#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: the tree root
 * Return: number or leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (tree->left == NULL || tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
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
 * binary_tree_is_full - checks if a binary tree is full
 * binary tree is full tree when...
 * Number of Leaf nodes = Number of Internal nodes + 1
 * @tree: the root
 * Return: the balance factor
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int leaves = binary_tree_leaves(tree);
	int nodes = binary_tree_nodes(tree);

	if (leaves == nodes + 1)
		return (1);
	else
		return (0);
}
