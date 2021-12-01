#include "hsh.h"

int get_builtin(char *line, char **args, int *ret)
{
	int i;
	builtin_t arr_builtin[] = {
		{"exit", end},
		{"env", _printenv},
		{NULL, NULL}
	};

	for (i = 0; arr_builtin[i].name != NULL; i++)
	{
		if (_strncmp(args[0], arr_builtin[i].name, 4) == 0)
			return (arr_builtin[i].fptr(line, args, ret, environ));
	}
	return (0);
}

int end(char *line, char **args, int *ret, char **environ)
{
	UNUSED(environ);
	_free_double_pointer(args);
	free(line);
	exit(*ret);
}

int _printenv(char *line, char **args, int *ret, char **environ)
{
	unsigned int i, len;
/*	char **env = environ;*/

	UNUSED(line);
	UNUSED(args);
	UNUSED(ret);

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
