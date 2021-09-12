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
	unsigned int cursor = 0, error = false;

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
		/* Check for match */
			/* Run opcode function */
	}
	printf("	->past while loop with opcode: %s on line %u\n", op, line);
	if (error)
		exit_error(ERR_INSTRUCTION, op, line);

	return (0);
}

void push()
{
	printf("in push\n");
	exit (1);
}
