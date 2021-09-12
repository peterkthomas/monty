#include "monty.h"

/**
 * file_reader - opens ans reads a monty bytecode file
 * @filename - file to open
 */
void file_reader(char *filename)
{
	FILE *fd = NULL;
	size_t size = 0;
	unsigned int line = 0;
	char *buffer = NULL;

	if (!filename)
		exit_error(ERR_FOPEN);

	/*  If access is not permitted, access() returns -1 */
	if (access(filename, R_OK) == -1)
		exit_error(ERR_FOPEN, filename);

	fd = fopen(filename, "r");

	if (!fd)
		exit_error(ERR_FOPEN, filename);

	/* read each line  --- MAIN PROGRAM LOOP */
	while (getline(&buffer, &size, fd))
	{
		if (!buffer)
			exit_error(ERR_MALLOC);
		line++; /* Line numbers always start at 1 */
		tokenize(buffer, line);
	}

	free(buffer);
	fclose(fd);
}

/**
 * tokenize - breaks up string to find opcode and value
 * @buffer: buffer of the string to break up
 * @line: line number we are on, for error printing
 *
 * Return: Always 0
 */
int tokenize(char *buffer, unsigned int line)
{
	char *op = NULL, *value = NULL;

	if(!buffer)
		exit_error(ERR_MALLOC);

	op = strtok(buffer, " \n");

	if (!op)
		return (0); /* next line plz */

	value = strtok(NULL, " \n");

	/* see if op is an opcode and run it */
	run_opcode(op, value, line);

	return (0);
}
