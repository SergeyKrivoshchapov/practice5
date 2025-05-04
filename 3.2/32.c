#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define N 5
#define C 3

void print_bytes(void *ptr, int size) 
{
	unsigned char *p = ptr;	
	for (int i = 0; i < size; i++) printf("%02x ", p[i]);
	printf("\n");
}

int main()
{
	int fd = open("21.bin", O_RDONLY);
	if (fd == -1) 
	{
		printf("error opening %s\n", strerror(errno));
		return 1;
	}
	printf("file opened.\n");
	
	char c;
	read(fd, &c, sizeof(c));
	print_bytes(&c, sizeof(c));
	
	char arr[C+1];	
	read(fd, arr, C);
	print_bytes(arr, C);

	short s;
	read(fd, &s, sizeof(s));
	print_bytes(&s, sizeof(s));

	int i;
	read(fd, &i, sizeof(i));
	print_bytes(&i, sizeof(i));

	int i_arr[N];
	read(fd, i_arr, sizeof(i_arr));
	print_bytes(i_arr, sizeof(i_arr));

	float f; 
	read(fd, &f, sizeof(f));
	print_bytes(&f, sizeof(f));

	double d;
	read(fd, &d, sizeof(d));
	print_bytes(&d, sizeof(d));

	if (close(fd) == -1)
	{
		printf("error closing %s\n", strerror(errno));
		return 1;
	}
	printf("data written. file closed.\n");
	return 0;
}
