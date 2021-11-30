#include "hsh.h"

/**
 * count_token - calculate the lenght of command line
 * @line: char pointer
 * Return: length of pointer
 */
unsigned int count_token(char *line)
{
	unsigned int count_tok = 0, i = 0, flag = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			flag = 1;
		if ((flag && line[i + 1] == ' ') || (flag && line[i + 1] == '\0'))
		{
			++count_tok;
			flag = 0;
		}
		++i;
	}
	return (count_tok);
}
/**
 * add - separate line in tokens and add to the matrix.
 * @line: command line
 * Return: matirx.
 */
char **add(char *line)
{
	char **command, *tok;
	unsigned int len, i;

	line[_strlen(line) - 1] = '\0';
	len = count_token(line);
	if (len == 0)
		return ('\0');

	command = malloc((sizeof(char *) * (len + 1)));
	if (command == NULL)
		return ('\0');

	i = 0;
	tok = strtok(line, " \t\n\r");
	while (tok != NULL)
	{
		command[i] = malloc(_strlen(tok) + 1);
		if (command[i] == NULL)
		{
			_free_double_pointer(command);
			return ('\0');
		}
		_strncpy(command[i], tok, _strlen(tok) + 1);
		tok = strtok(NULL, " \t\n\r");
		++i;
	}
	command[i] = NULL;
	return (command);
}


