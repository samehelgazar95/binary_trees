#include "binary_trees.h"
#define SIZE 10

/**
 * q - create queue
 * @front: the first element
 * @rear: the last element
 * Return: Array of pointers to nodes
 */
binary_tree_t **q(int *front, int *rear)
{
	binary_tree_t **queue = calloc(sizeof(binary_tree_t *), SIZE);
	*front = *rear = 0;
	return (queue);
}

/**
 * enq - enqueue to queue
 * @q: the queue
 * @rear: the first element
 * @node: the node to enqueue
 * Return: Nothing
 */
void enq(binary_tree_t **q, int *rear, binary_tree_t *node)
{
	q[*rear] = node;
	(*rear)++;
}

/**
 * deq - dequeue from the queue
 * @q: the queue
 * @front: the first node
 * Return: the dequeued node
 */

binary_tree_t *deq(binary_tree_t **q, int *front)
{
	(*front)++;
	return (q[*front - 1]);
}

/**
 * binary_tree_levelorder - Print with BFS Algo
 * @tree: the root
 * @func: the printing func
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	const binary_tree_t *temp = tree;
	binary_tree_t **queue = q(&front, &rear);

	while (temp)
	{
		func(temp->n);

		if (temp->left)
			enq(queue, &rear, temp->left);

		if (temp->right)
			enq(queue, &rear, temp->right);

		if (rear >= front)
			temp = deq(queue, &front);
	}
}
