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
