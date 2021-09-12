#include "monty.h"

/**
 * push - push a node onto the stack
 * @new: pointer to new node
 * @line: line number
 */
void push(node_t **new, unsigned int line __attribute__((unused)))
{
	node_t *temp_node;

	if (!new)
	{
		printf("in exit_fail\n");
		exit(EXIT_FAILURE);
	}

	if (!node)
	{
		printf("in push()\n");
		node = *new;
		return;
	}

	temp_node = node;
	temp_node->prev = NULL;
	node = *new;
	node->next = temp_node;
	temp_node->prev = node;
	printf("in push()\n");
}

/**
 * pall - prints all items on stack
 */
void pall(node_t **top, unsigned int line __attribute__((unused)))
{
	node_t *temp_node;

	printf("in pall()\n");
	if(!top)
		exit(EXIT_FAILURE);
	temp_node = *top;
	while (temp_node)
	{
		fprintf(stdout, "%d\n", temp_node->n);
		temp_node = temp_node->next;
	}
}

/**
 * nop - do nothing
 * @top: pointer to the top of stack
 * @line: line number(unused)
 */
void nop(node_t **top, unsigned int line __attribute__((unused)))
{
	(void)top;
}

/**
 * pint - prints contents of the top node on the stack
 * @top: double pointer to top node of stack
 * @line: line number
 */
void pint(node_t **top, unsigned int line __attribute__((unused)))
{
	if (!top)
		exit(EXIT_FAILURE); /* needs pint error handling */

	printf("%d\n", (*top)->n);
}
