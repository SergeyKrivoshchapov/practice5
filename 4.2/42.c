#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define N 5
#define C 3

int main()
{
	int fd = open("21.bin", O_RDWR);
	if (fd == -1) 
	{
		printf("error opening %s\n", strerror(errno));
		return 1;
	}
	printf("file opened.\n");
	
	lseek(fd, (int)sizeof(char) * (1 + 2) , SEEK_SET); // char + 0, 1 index of array
	char char_tochange = 'A';
	write(fd, &char_tochange, sizeof(char_tochange));

	lseek(fd, sizeof(short) + sizeof(int) + sizeof(int) * 5 , SEEK_CUR); // short, int, int array
		
	float float_tochange = 6.5358f;
	write(fd, &float_tochange, sizeof(float_tochange));

	if (close(fd) == -1)
	{
		printf("error closing %s\n", strerror(errno));
		return 1;
	}
	printf("file closed.\n");
	return 0;
}


