#include "binary_trees.h"

/**
* binary_tree_insert_right - Inserting new_node to the right of the parent
*
* @parent: The parent
* @value: The value
* Return: return the new_node or NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node || !parent)
		return (NULL);

	new_node->right = parent->right;
	if (new_node->right)
		new_node->right->parent = new_node;
	parent->right = new_node;

	return (new_node);
}
