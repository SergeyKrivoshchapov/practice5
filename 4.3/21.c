#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
        int fd = open("21.bin", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd == -1) 
        {
                printf("error opening %s\n", strerror(errno));
                return 1;
        }
        printf("file created and opened.\n");

        char c = 'A';
        write(fd, &c, sizeof(c));

        char arr[] = "arr";
        write(fd, arr, strlen(arr));

        short s = 3141;
        write(fd, &s, sizeof(s));

        int i = 31413141;
        write(fd, &i, sizeof(i));

        int i_arr[] = {1, 2, 3, 4, 5};
        write(fd, i_arr, sizeof(i_arr));

        float f = 1.23f; 
        write(fd, &f, sizeof(f));

        double d = 1.2345678999;
        write(fd, &d, sizeof(d));

        if (close(fd) == -1)
        {
                printf("error closing %s\n", strerror(errno));
                return 1;
        }
        printf("data written. file closed.\n");
        return 0;
}

