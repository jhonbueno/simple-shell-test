#include "hsh.h"

/**
 * get_builtin - select the bulitin from the array of builtins.
 * @line: the command in line.
 * @args: the command + his arguments in a matrix.
 * @ret: pointer to return value.
 *
 * Return: 0 if not find the bultin, 1 else.
 */
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

/**
 * end - finishes the progrman with ret.
 * @line: the command in line.
 * @args: the command + his arguments in a matrix.
 * @ret: pointer to return value.
 * @environ: environment variable.
 *
 * Return: end the execution of the shell.
 */
int end(char *line, char **args, int *ret, char **environ)
{
	UNUSED(environ);
	_free_double_pointer(args);
	free(line);
	exit(*ret);
}

/**
 * _printenv - prints the environment.
 * @line: the command in line.
 * @args: the command + his arguments in a matrix.
 * @ret: pointer to return value.
 * @environ: environment variable.
 *
 * Return: 1 if sucess.
 */
int _printenv(char *line, char **args, int *ret, char **environ)
{
	unsigned int i, len;

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
