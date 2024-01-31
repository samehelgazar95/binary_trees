#include "binary_trees.h"

/**
 * binary_trees_ancestor - the lowest common ancestor of two nodes
 * @first: the first node
 * @second: the second node
 * Return: The ancestor
 */

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *s;

	while (first)
	{
		s = second;
		while (s)
		{
			if (s->n == first->n)
				return ((binary_tree_t *)first);
			s = s->parent;
		}
		first = first->parent;
	}

	return (NULL);
}
