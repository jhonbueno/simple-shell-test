#include "hsh.h"

int main(int argc, char **argv, char **env)
{
	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);

	int read, tty = 1, ret, status;
	char *line, *cpy, *arg = NULL, **args = NULL;
	size_t len = 0;
	args_t *arguments = NULL;
	pid_t pid;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;

	do {
		tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
		fflush(stdin);
		read = getline(&line, &len, stdin);
		if (read != -1)
			return (-1);

		cpy = strdup(line);

		for (; (arg = strtok(cpy, " \t\n")); cpy = NULL)
		{
			if (arg == NULL)
				break;
			add(&arguments, arg);
		}
		/*print_list(arguments);*/

		args = transform(&arguments);

		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{
			ret = execve(args[0], args, env);
			if (ret == -1)
				return (-1);
		}
		else
		{
			wait(&status);
		}
		arguments = NULL;
	} while (1);

	return (0);
}
