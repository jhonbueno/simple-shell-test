#include "hsh.h"


int main(void)
{
    pid_t pid;
    int read, tty = 1, ret = 0, status = 0;
    char *line = NULL, **args = NULL;
    size_t len = 0;

    isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;


    do {
        /* read */

        tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
        fflush(stdin);
        read = getline(&line, &len, stdin);
        if(read == -1)
	{
		printf("\n");
		return (-1);
	}

        /* Parse */

        args = add(line);

        /* execute */

        pid = fork();

        if(pid == -1)
            return (-1);

        else if (pid == 0)
        {
		if (execve(findpath(args[0], &ret), args, environ) == -1)
		{
			_free_double_pointer(args);
			exit(ret);
		}
        }
        else
	{
		wait(&status);
		_free_double_pointer(args);
	}

	/* clean */
	line = NULL;

    }while(1);
    free(line);
    return (0);
}
