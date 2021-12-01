#ifndef _H_SHELL
#define _H_SHELL


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

/**
 * struct builtin_s - Struct that represents a builtin function.
 *
 * @name:the name of the bulitin.
 * @fptr: the function pointer.
 */
typedef struct builtin_s
{
	char *name;
	int (*fptr)(char *line, char **args, int *, char **);
} builtin_t;

int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strncpy(char *dest, char *src, int n);
char **add(char *line);
char *findpath(char *command, int *ret);
void _free_double_pointer(char **d_pointer);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
int get_builtin(char *line, char **args, int *ret);
int end(char *line, char **args, int *ret, char **environ);
int _printenv(char *line, char **args, int *ret, char **environ);

#define UNUSED(x) (void)(x)

#endif /* _H_SHELL */
