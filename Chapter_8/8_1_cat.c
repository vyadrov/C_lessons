#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

void filecopy(int from, int to);

int main(int argc, char *argv[]) {
    int fd;    

    if (argc == 1)
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                printf("cat: Can't open file %s\n", *argv);
                return 1;
            }
            else {
                filecopy(fd, 1);
                close(fd);
            }

    return 0;
}

void filecopy(int from, int to) {
    int n;
    char buf[BUFSIZE];

    while ((n = read(from, buf, BUFSIZE)) > 0)
        write(to, buf, n);
}