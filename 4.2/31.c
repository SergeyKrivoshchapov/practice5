#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define C 3
#define N 5

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
        printf("char value %c\n", c);

        char arr[C+1];
        read(fd, arr, C);
        arr[C] = '\n';
        printf("char arr: %s\n", arr);

        short s;
        read(fd, &s, sizeof(s));
        printf("short value %hd\n", s);

        int i;
        read(fd, &i, sizeof(i));
        printf("int value %d\n", i);

        int i_arr[N];
        read(fd, i_arr, sizeof(i_arr));
        printf("int arr:\n");
        for (int count = 0; count < N; count++) printf(" %d", i_arr[count]);

        float f; 
        read(fd, &f, sizeof(f));
        printf("\nfloat value %f\n", f);

        double d;
        read(fd, &d, sizeof(d));
        printf("double value %.15lf\n", d);

        if (close(fd) == -1)
        {
                printf("error closing %s\n", strerror(errno));
                return 1;
        }
        printf("data written. file closed.\n");
        return 0;
}

