#ifndef _H_SHELL
#define _H_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

typedef struct args_s
{
	char *arg;
	struct args_s *next;
} args_t;



#define UNUSED(x) (void)(x);


#endif /* _H_SHELL */
