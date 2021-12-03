#include "hsh.h"

/**
 * print_errors - print errors.
 * @commandtoprint: input command.
 *
 * Return: none.
 */

void print_errors(char *argv_0, int count_t, char *commandtoprint)
{
	write(STDERR_FILENO, argv_0, _strlen(argv_0));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, (count_t + '0'), 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, commandtoprint, _strlen(commandtoprint));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found", 9);
}


/**
 * _getenv - funtion to get the PATH form the environment variable.
 * @name: the string to find in the environment variable.
 *
 * Return: the PATH directories.
 */

char *_getenv(const char *name)
{
	int len = strlen((char *)name);
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
		{
			return (*env + len + 1);
		}
		env++;
	}
	return (NULL);
}

/**
 * findpath - retrive path from getenv and find mach using the command.
 * @command: args[0] the commmand.
 * @ret: return value.
 *
 * Return: the complete path for executing non-built-ins.
 */

char *findpath(char *command, int *ret, char *argv_0)
{
	char *path, *commandtoprint;
	struct stat stats;
	char *current_source;
	char *tok;

	if (stat(command, &stats) == 0)
		return (command);

	path = _getenv("PATH");
	tok = strtok(path, ":");
	commandtoprint = command;
	command = str_concat("/", command);

	while (tok != NULL)
	{
		current_source = str_concat(tok, command);

		if (stat(current_source, &stats) == 0)
		{
			free(command);
			return (current_source);
		}
		free(current_source);
		tok = strtok(NULL, ":");
	}

	print_errors(argv_0, count_token(command), commandtoprint);
	free(command);
	*ret = 127;
	return (NULL);
}
