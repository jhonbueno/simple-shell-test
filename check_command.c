#include "hsh.h"

char *_getenv(const char *name)
{
	int len = strlen((char *)name);
	char **env = environ;
	char *my_path;

	while (*env != NULL)
	{
		if (strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
		{
			/*my_path = malloc(sizeof(char) * strlen(*env + len + 1));*/
			my_path = strdup(*env + len + 1);
			printf("%s\n", my_path);
			return (my_path);
		}
		env++;
	}
	return (NULL);
}

char *findpath(char *command, int *ret)
{
	char *path; /* commandtoprint */
	struct stat stats;
	char *current_source;
	char *tok;

	if (stat(command, &stats) == 0)
		return (command);

	path = _getenv("PATH");
	printf("PATH: %s", path);
	tok = strtok(path, ":");
/*	commandtoprint = command;*/
	command = strcat("/", command);

/*stat() returns 0 on successful operation,*/
/* otherwise returns -1 if unable to get file properties.*/
	while (tok != NULL)
	{
		current_source = strcat(tok, command);
		printf("Inicio del while: %s\n", current_source);
		if (stat(current_source, &stats) == 0)
		{
			free(command);
			printf("%s\n", current_source);
			return (current_source);
		}
		free(current_source);
		tok = strtok(NULL, ":");
	}

	printf("No entró al match\n");
	/*error_printing(path, find_length(command), commandtoprint);
	  print_string(": not found", 0);*/
	free(command);
	*ret = 127;
	return (NULL);
}
