#include "monty.h"

/**
 * run_opcode - checks for an opcode and runs it
 * @op: opcode to check
 * @value: value after opcode
 * @line: line number for error handling
 *
 * Return: Always 0
 */
int run_opcode(char *op, char *value __attribute__((unused)), unsigned int line)
{
	unsigned int cursor = 0, error = true;

	/* Opcodes to match and function pointer to execute */
	instruction_t codes[] = {
		{"push", push},
		{NULL, NULL}
	};

	printf("in run_opcode()\n");
	/* look for a matching opcode */
	while (codes[cursor].opcode)
	{
		cursor++;
		if (strcmp(op, codes[cursor].opcode) == 0)
		{
			/* Run opcode function */
			invoke(op, value, codes[cursor].opcode, line);
			error = false;
		}
	}
	printf("	->past while loop with opcode: %s on line %u\n", op, line);
	if (error)
		exit_error(ERR_INSTRUCTION, op, line);

	return (0);
}

void invoke(char *op, char *value, op_invoke f, unsigned int line)
{
	node_t *temp_node;
	int i = 0, mult = 1;

	if (strcmp(op, "push"))
	{
		if (!value)
			perror("ERROR"); /* fix */
		if (value[0] == '-')
		{
			i++;
			mult = -1;
		}
		while (value[i])
		{
			if (!isdigit(value[i]))
			{
				/* error */
			}
			i++;
		}
		temp_node = create_node(atoi(value) * mult);
		f(&temp_node, line);
	}
	else
		f(&node, line);
}
