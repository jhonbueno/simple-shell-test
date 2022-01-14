#include "hsh.h"

/**
 * print_errors - print errors.
 * @argv_0: argv in position 0.
 * @count_t: count of tokens in command.
 * @commandtoprint: input command.
 *
 * Return: none.
 */

void print_errors(char *argv_0, int count_t, char *commandtoprint)
{
	char num;

	num = count_t + '0';
	  write(STDERR_FILENO, argv_0, _strlen(argv_0));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &num, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, commandtoprint, _strlen(commandtoprint));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
}

/**
 * _getenv - funtion to get the PATH form the environment variable.
 * @name: the string to find in the environment variable.
 *
 * Return: the PATH directories.
 */

char *_getenv(const char *name)
{
	int len = _strlen((char *)name);
	char **env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
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
 * @argv_0: argv on 0 position.
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
