#include "hsh.h"

/**
 * main - UNIX command line interpreter
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t pid;
	int read, tty = 1, ret = 0, status = 0;
	char *line = NULL, **args = NULL;
	size_t len = 0;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	do {
		tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
		fflush(stdin);
		read = getline(&line, &len, stdin);
		if (read == EOF)
			break;
		if (*line == '\n' || *line == '\t')
			continue;
		args = add(line);
		if (args == NULL)
			continue;
		if (get_builtin(line, args, &ret) == 0)
		{
			pid = fork();
			if (pid == -1)
				return (-1);
			else if (pid == 0)
			{
				if (execve(findpath(args[0], &ret),
					   args, environ) == -1)
				{
					_free_double_pointer(args);
					exit(ret);
				}
			} else
			{
				wait(&status);
				_free_double_pointer(args);
			} line = NULL;
		} else
			_free_double_pointer(args);
	} while (1);
	free(line);
	return (0);
}
