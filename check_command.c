#include "hsh.h"

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

char *findpath(char *command, int *ret)
{
	char *path/*,*commandtoprint*/;
	struct stat stats;
	char *current_source;
	char *tok;

	printf("Imprime el comando: %s\n", command);

	if (stat(command, &stats) == 0)
		return (command);
	printf("Hola mundo after if\n");

	path = _getenv("PATH");
	printf("Hola, after getenv");
	tok = strtok(path, ":");
	printf("Tok: %s", tok);
/*	commandtoprint = command;*/
	command = strcat("/", command);
	printf("Imprime el comando 2: %s\n", command);

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

	porintf("No entró al match\n");
	/*error_printing(path, find_length(command), commandtoprint);
	  print_string(": not found", 0);*/
	free(command);
	*ret = 127;
	return (NULL);
}
