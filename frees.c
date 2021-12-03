#include "hsh.h"
/**
 * _free_double_pointer - Entry point
 * @d_pointer: double pointer
 * Return: void
 */
void _free_double_pointer(char **d_pointer)
{
	unsigned int i = 0;

	if (d_pointer == NULL)
		return;

	while (d_pointer[i])
	{
		free(d_pointer[i]);
		++i;
	}

	if (d_pointer[i] == NULL)
		free(d_pointer[i]);

	free(d_pointer);
}
/**
 * free_two - frees both line and the matix.
 * @line: string with the command and arguments.
 * @args: matrix of tokens.
 *
 * Return: void.
 */
void free_two(char *line, char **args)
{
	free(line);
	_free_double_pointer(args);
}
