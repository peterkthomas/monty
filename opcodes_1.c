#include "monty.h"

/**
 * push - push a node onto the stack
 * @new: pointer to new node
 * @line: line number
 */
void push(node_t **new, unsigned int line __attribute__((unused)))
{
	node_t *temp_node;

	if (!new || !*new)
		exit(EXIT_FAILURE);

	if (!node)
	{
		node = *new;
		return;
	}

	temp_node = node;
	temp_node->prev = NULL;
	node = *new;
	node->next = temp_node;
	temp_node->prev = node;
}

/**
 * pall - prints all items on stack
 * @top: pointer to the top node of stack
 * @line: line number to print
 */
void pall(node_t **top, unsigned int line __attribute__((unused)))
{
	node_t *temp_node;

	if (top && *top)
	{
		temp_node = *top;
		while (temp_node)
		{
			fprintf(stdout, "%d\n", temp_node->n);
			temp_node = temp_node->next;
		}
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
void pint(node_t **top, unsigned int line)
{
	if (!top || !*top)
		exit_error(ERR_PINT, line, "can't pint, stack empty");

	printf("%d\n", (*top)->n);
}

/**
 * pop - pops a node off the top of the stack
 * @top: double pointer to the top node of stack
 * @line: line number
 */
void pop(node_t **top, unsigned int line)
{
	node_t *temp_node;

	if (!top || !*top)
		exit_error(ERR_POP, line);

	temp_node = *top;
	*top = temp_node->next;
	if (*top)
		(*top)->prev = NULL;
	free(temp_node);
}
