#include "monty.h"

/**
 * swap - swaps the top two items on stack
 * @top: top item in stack
 * @line: line number for error handling
 */
void swap(node_t **top, unsigned int line __attribute__((unused)))
{
	node_t *temp_node;

	if (!top)
		exit(EXIT_FAILURE); /* add error handling */

	temp_node = (*top)->next;
	(*top)->next = temp_node->next;

	if (temp_node->next)
		temp_node->next->prev = *top;

	temp_node->next = *top;
	(*top)->prev = temp_node;

	temp_node->prev = NULL;
	*top = temp_node;
}
