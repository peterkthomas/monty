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
	int status = 0;

	if (argc != 2)
		exit_error(ERR_ARGCOUNT);

	status = file_reader(argv[1]);

	destroy_nodes();
	return (status);
}
