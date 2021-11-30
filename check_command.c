#include "hsh.h"
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
char *findpath(char *command, int *ret)
{
	char *path/*, *commandtoprint*/;
	struct stat stats;
	char *current_source;
	char *tok;

	if (stat(command, &stats) == 0)
		return (command);

	path = _getenv("PATH");
	tok = strtok(path, ":");
	/*	commandtoprint = command;*/
	command = str_concat("/", command);

	/*stat() returns 0 on successful operation,*/
	/* otherwise returns -1 if unable to get file properties.*/
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
	/*error_printing(path, find_length(command), commandtoprint);*/
	/*print_string(": not found", 0);*/
	free(command);
	*ret = 127;
	return (NULL);
}
