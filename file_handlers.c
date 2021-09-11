#include "monty.h"

/**
 * file_reader - opens ans reads a monty bytecode file
 * @filename - file to open
 */

void file_reader(char *filename)
{
	FILE *fd;
	size_t size = 0;
	unsigned int lines = 0;
	char *buffer = NULL;

	if (!filename)
		print_error(ERR_FOPEN);

	/*  If access is not permitted, access() returns -1 */
	if (access(filename, R_OK) == -1)
		print_error(ERR_FOPEN, filename);

	fd = fopen(filename, "r");

	if (!fd)
		print_error(ERR_FOPEN, filename);

	/* read each line */
	while (getline(&buffer, &size, fd))
	{
		/* tokenizer function */
		lines++;
	}

	free(buffer);
	fclose(fd);
}
