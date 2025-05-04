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

        lseek(fd, 1, SEEK_SET); // char

        char arr[C+1];
        read(fd, arr, C);
        arr[C] = '\0';

        int arr_half = C / 2;
        for (int i = 0; i < arr_half; i++)
        {
                char tmp = arr[i];
                arr[i] = arr[C - i - 1];
                arr[C - i - 1] = tmp;
        }

        lseek(fd, 1, SEEK_SET);
        write(fd, arr, sizeof(arr)); 
        
        if (close(fd) == -1)
        {
                printf("error closing %s\n", strerror(errno));
                return 1;
        }
        printf("file closed.\n");
        return 0;
}

