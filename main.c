#include "hsh.h"

int main(int argc, char **argv, char **env)
{
	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);

	int read, tty = 1, argCount;
	char *line, *cpy, *arg = NULL;
	size_t len = 0;
	args_t *arguments;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;

	do {

		tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
		fflush(stdin);
		read = getline(&line, &len, stdin);
		if (read != -1)
			return (-1);

		cpy = strdup(line);

		for (argCount = 1; (arg = strtok(cpy, " \t\n")); argCount++,
			     cpy = NULL)
		{
			if (arg == NULL)
				break;
			add(&arguments, arg);
		}
	} while (1);

	return (0);
}
