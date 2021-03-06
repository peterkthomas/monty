#include "monty.h"

/**
 * destroy_nodes - releases all node_t nodes
 */
void destroy_nodes(void)
{
	node_t *temp_node;

	if (!node)
		return;

	while (node)
	{
		temp_node = node;
		node = node->next;
		free(temp_node);
	}

}

/**
 * create_node - provisions a new node_t node
 * @num: value to add to the node (int)
 *
 * Return: Pointer to the new node, or NULL.
 */
node_t *create_node(int num)
{
	node_t *new;

	new = malloc(sizeof(node_t));
	if (!new)
		exit_error(ERR_MALLOC);

	new->n = num;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
