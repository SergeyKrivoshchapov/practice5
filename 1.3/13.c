#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd = open("1.bin", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1) 
	{
		printf("error opening %s\n", strerror(errno));
		return 1;
	}
	printf("file opened. is able to append in it.\n");

	if (close(fd) == -1)
	{
		printf("error closing %s\n", strerror(errno));
		return 1;
	}
	printf("file closed\n");
	return 0;
}
