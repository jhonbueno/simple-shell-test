#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("README.md", O_WRONLY | O_APPEND);

	if (fd == -1)
		
