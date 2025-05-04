#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define N 5
#define C 3

int main()
{
	int fd = open("21.bin", O_RDONLY);
	if (fd == -1) 
	{
		printf("error opening %s\n", strerror(errno));
		return 1;
	}
	printf("file opened.\n");
	
	lseek(fd, 1, SEEK_SET); // char

	char arr[C+1];
	read(fd, arr, C);
	printf("char array: %s\n", arr);

	lseek(fd, 2, SEEK_CUR); // short

	int i;
	read(fd, &i, sizeof(i));
	printf("int value: %d\n", i);

	lseek(fd, N * (int)sizeof(int) + sizeof(float), SEEK_CUR); // int array, float

	double d;
	read(fd, &d, sizeof(d));
	printf("double value: %.15lf\n", d);

	if (close(fd) == -1)
	{
		printf("error closing %s\n", strerror(errno));
		return 1;
	}
	printf("file closed.\n");
	return 0;
}
