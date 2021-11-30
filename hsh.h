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

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */

typedef struct path_s
{
    char* path;
    struct args_s *next;
} path_t;

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */
typedef struct args_s
{
    char* arg;
    struct args_s *next;
} args_t;

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */

extern char **environ;

args_t *add(args_t **head, char* arg);
char **transform(args_t **head);
char *findpath(char *command, int *ret);
void _free_double_pointer(char **d_pointer);
char *str_concat(char *s1, char *s2);
void free_list(args_t **head);
char *_strdup(char *str);

#define UNUSED(x) (void)(x);

#endif /* _H_SHELL */
