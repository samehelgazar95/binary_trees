#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserting new_node to the left of the parent
 *
 * @parent: The parent
 * @value: The value
 * Return: return the new_node or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	new_node->left = parent->left;
	if (parent->left != NULL)
		new_node->left->parent = new_node;
	parent->left = new_node;

	return (new_node);
}