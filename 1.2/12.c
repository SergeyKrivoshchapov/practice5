#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = open("12.bin", O_WRONLY | O_CREAT | O_EXCL, 0644);
	if (fd == -1)
	{
		printf("error creating %s\n", strerror(errno));
		return 1;
	}
	printf("file created and opened\n");
	
	if (close(fd) == -1)
	{
		printf("error closing %s\n", strerror(errno));
		return 1;
	}
	printf("file closed\n");

	fd = open("12.bin", O_WRONLY | O_CREAT | O_EXCL, 0644);

	if (fd == -1)
	{
		printf("error creating !! %s\n", strerror(errno));
		return 1;
	}
	printf("file created and opened\n");
	
	if (close(fd) == -1)
	{
		printf("error closing %s\n", strerror(errno));
		return 1;
	}
	printf("file closed\n");
	
	return 0;
}
