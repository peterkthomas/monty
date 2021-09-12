#include "monty.h"

/**
 * exit_error - Writes error messages
 * @id: ID of the error message to print
 */
void exit_error(unsigned int id, ...)
{
	va_list args;
	unsigned int line;
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
			op = va_arg(args, char *);
			line = va_arg(args, unsigned int);
			fprintf(stderr, "L%u: unknown instruction %s\n", line, op);
			break;
		default:
			break;
	}

	va_end(args);
	exit(EXIT_FAILURE);
}
