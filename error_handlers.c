#include "monty.h"

/**
 * print_error - Writes error messages
 * @id: ID of the error message to print
 */

void print_error(unsigned int id, ...)
{
	va_list args;

	va_start(args, id);
	switch (id)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		default:
			break;
	}

	exit(EXIT_FAILURE);
}
