#include "monty.h"
node_t *node = NULL;

/**
 * main - Monty interpreter
 * @argc: number of arguments passed
 * @argv: argument vectors/variables
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		exit_error(ERR_ARGCOUNT);

	file_reader(argv[1]);

	return (0);
}
