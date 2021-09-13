#include "monty.h"

/**
 * swap - swaps the top two items on stack
 * @top: top item in stack
 * @line: line number for error handling
 */
void swap(node_t **top, unsigned int line)
{
	node_t *temp_node;

	if (!top || !*top || !(*top)->next)
		exit_error(ERR_SWAP, line);

	temp_node = (*top)->next; /* temp node is node after head node */
	(*top)->next = temp_node->next;

	if (temp_node->next)
		temp_node->next->prev = *top;

	temp_node->next = *top;
	(*top)->prev = temp_node;

	temp_node->prev = NULL;
	*top = temp_node;
}

/**
 * add - adds the values of the top two nodes in the stack
 * @top: top item in stack
 * @line: line number for error handling
 */
void add(node_t **top, unsigned int line __attribute__((unused)))
{
	int val;

	if (!top || !*top || !(*top)->next)
		exit_error(ERR_ADD, line);

	(*top) = (*top)->next;
	val = (*top)->n + (*top)->prev->n;
	(*top)->n = val;
	free((*top)->prev);
	(*top)->prev = NULL;
}
