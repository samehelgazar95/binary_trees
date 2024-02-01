#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: the tree root
 * Return: the depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - the lowest common ancestor of two nodes
 * First Solution is O(n), Second is O(n^2)
 * @first: the first node
 * @second: the second node
 * Return: The ancestor
 */

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	while (first_depth < second_depth)
	{
		second = second->parent;
		second_depth--;
	}

	while (second_depth < first_depth)
	{
		first = first->parent;
		first_depth--;
	}

	while (1)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}

/**
 * binary_trees_ancestor - the lowest common ancestor of two nodes
 * First Solution is O(n), Second is O(n^2)
 * @first: the first node
 * @second: the second node
 * Return: The ancestor
 *binary_tree_t *binary_trees_ancestor(
 *		const binary_tree_t *first, const binary_tree_t *second)
 *
 *{
 *	const binary_tree_t *s;
 *	while (first)
 *
 *	{
 *		s = second;
 *		while (s)
 *
 *		{
 *			if (s->n == first->n)
 *				return ((binary_tree_t *)first);
 *			s = s->parent;
 *
 *		}
 *		first = first->parent;
 *
 *	}
 *	return (NULL);
 *
 *}
 */
