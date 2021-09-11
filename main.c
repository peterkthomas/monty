#include "monty.h"
stack_t *node = NULL;

int main(int argc, char **argv)
{
	if (argc != 2 && argv[1])
	{
		// Do error stuff
	}

	file_open(argv[1]);

	free_list();

	return (0);
}