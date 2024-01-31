#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the node
 * Return: the node or null
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left->left->n == node->n ||
		node->parent->parent->left->right->n == node->n)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
