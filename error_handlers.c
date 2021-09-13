#include "monty.h"

/**
 * exit_error - Writes error messages and exits
 * @id: ID of the error message to print
 */
void exit_error(unsigned int id, ...)
{
	va_list args;
	char *op;

	va_start(args, id);
	switch (id)
	{
		case ERR_ARGCOUNT:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERR_FOPEN:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case ERR_MALLOC:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case ERR_INSTRUCTION:
			va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n",
					va_arg(args, unsigned int), va_arg(args, char *));
			break;
		case ERR_PUSH:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(args, unsigned int));
			break;
		case ERR_PINT:
			fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}

	va_end(args);
	destroy_nodes();
	exit(EXIT_FAILURE);
}
