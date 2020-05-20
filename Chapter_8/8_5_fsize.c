#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "list.h"

MYDIR *myopendir(char *dirname);
Dirent *myreaddir(MYDIR *dfd);

void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);

    printf("%8ld %s\n%u %ld\n", stbuf.st_size, name,  stbuf.st_uid,stbuf.st_mtime);
}

void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    Dirent *dp;
    MYDIR *dfd;

    if ((dfd = myopendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: cant open %s\n", dir);
        return;
    }

    while((dp = myreaddir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    myclosedir(dfd);
}

MYDIR *myopendir(char *dirname) {
    int fd;
    struct stat stbuf;
    MYDIR *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (MYDIR *) malloc(sizeof(MYDIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp;
}

void myclosedir(MYDIR *dp) {
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}

Dirent *myreaddir(MYDIR *dp) {
    struct direct dirbuf;
    static Dirent d;

    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0)
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}