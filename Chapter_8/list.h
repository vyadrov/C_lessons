#ifndef LIST_H
#define LIST_H
#define NAME_MAX_LEN 14
#define MAX_PATH 1024

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {
    ino_t d_ino;
    char d_name[DIRSIZ];
};

typedef struct {
    long ino;
    char name[NAME_MAX_LEN + 1];
} Dirent;

typedef struct {
    int fd;
    Dirent d;
} MYDIR;

void myclosedir(MYDIR *dfd);
void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

#endif