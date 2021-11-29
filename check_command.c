#include "hsh.h"

char *_getenv(const char *name)
{
	int len = _strlen((char *)name);
	char **env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0
		    && env[0][len] == '=')
			return (*env + len + 1); env++;
	}
	return (NULL);
}

char *findpath(char *command, int *retVal)
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
	error_printing(path, find_length(command), commandtoprint);
	print_string(": not found", 0);
	free(command);
	*retVal = 127;
	return (NULL);
}
