#include "monty.h"
/**
 * exit_error - Writes error messages and exits
 * @id: ID of the error message to print
 */
void exit_error(unsigned int id, ...)
{
	va_list args;

	va_start(args, id);
	if (id == ERR_ARGCOUNT)
		fprintf(stderr, "USAGE: monty file\n");
	else if (id == ERR_FOPEN)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	else if (id == ERR_MALLOC)
		fprintf(stderr, "Error: malloc failed\n");
	else if (id == ERR_INSTRUCTION)
		fprintf(stderr, "L%u: unknown instruction %s\n",
				va_arg(args, unsigned int), va_arg(args, char *));
	else if (id == ERR_PUSH)
		fprintf(stderr, "L%u: usage: push integer\n", va_arg(args, unsigned int));
	else if (id == ERR_PINT)
		fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(args, unsigned int));
	else if (id == ERR_POP)
		fprintf(stderr, "L%u: can't pop an empty stack\n",
					va_arg(args, unsigned int));
	else if (id == ERR_SWAP)
		fprintf(stderr, "L%u: can't swap, stack too short\n",
					va_arg(args, unsigned int));
	else if (id == ERR_ADD)
		fprintf(stderr, "L%u: can't add, stack too short\n",
					va_arg(args, unsigned int));
	va_end(args);
	destroy_nodes();
	exit(EXIT_FAILURE);
}
