#include "monty.h"

/**
 * run_opcode - checks for an opcode and runs it
 * @op: opcode to check
 * @value: value after opcode
 * @line: line number for error handling
 *
 * Return: Always 0
 */
int run_opcode(char *op, char *value, unsigned int line)
{
	unsigned int cursor = 0, error = true;

	/* Opcodes to match and function pointer to execute */
	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	/* look for a matching opcode */
	while (codes[cursor].opcode)
	{
		if (strcmp(op, codes[cursor].opcode) == 0)
		{
			/* Run opcode function */
			invoke(op, value, codes[cursor].f, line);
			error = false;
		}
		cursor++;
	}
	if (error)
		exit_error(ERR_INSTRUCTION, op, line);

	return (0);
}

int invoke(char *op, char *value, op_invoke f, unsigned int line)
{
	node_t *temp_node;
	int i = 0, mult = 1;

	if (strcmp(op, "push") == 0)
	{
		if (!value)
			perror("No Value For PUSH"); /* fix */
		if (value[0] == '-')
		{
			i++;
			mult = -1;
		}
		while (value[i])
		{
			if (!isdigit(value[i]))
			{
				perror("No Digit in Push");/* error */
			}
			i++;
		}
		temp_node = create_node(atoi(value) * mult);
		f(&temp_node, line);
	}
	else
		f(&node, line);

	return (0);
}
