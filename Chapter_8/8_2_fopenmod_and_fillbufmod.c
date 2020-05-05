#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define EOF (-1)
#define OPEN_MAX 20
#define PERMS 0666
#define getcx(p) (--(p)->cnt >= 0? (unsigned char) *(p)->ptr++:_fillbufmod(p))

typedef struct _flags{
    int _READ;
    int _WRITE;
    int _UNBUF;
    int _EOF;
    int _ERR;
} flags;

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    struct _flags flags;
    int fd;
} FILEmod;

FILEmod _iob[OPEN_MAX];

int _fillbufmod(FILEmod *f);
int is_empty(struct _flags flags){
    if (!flags._READ && !flags._WRITE && !flags._UNBUF && !flags._EOF && !flags._ERR)
        return 1;
    return 0;
}

FILEmod *fopenmod(char *name, char *mode) {
    
    int fd;
    FILEmod *fp;
    if (*mode != 'r' && *mode != 'w' && *mode != 'a' )
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (is_empty(fp->flags))
            break;
    if (fp >= _iob + OPEN_MAX)
        return NULL;
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if ( *mode == 'a') {
        if ((fd = open(name, O_RDONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    }
    else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;

    if (*mode == 'r')
        fp->flags._READ = 1;
    else
        fp->flags._WRITE = 1;

    return fp;
}

int _fillbufmod(FILEmod *fp) {

    int bufsize;

    if (fp->flags._READ == 0)
        return EOF;
    bufsize = (fp->flags._UNBUF != 0) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *) malloc (bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt< 0){

        if (fp->cnt == -1)
            fp->flags._EOF = 1;
        else
            fp->flags._ERR = 1;
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char) *fp->ptr++;
}

int main(int argc, char* argv[]){
    clock_t start, end;
    FILEmod *fp;
    char c;

    while (--argc > 0) {
        start = clock();
        if ((fp = fopenmod(*++argv, "r")) == NULL) {
            printf("cat: can't open %s\n", *argv);
            return 1;        
        } else {
            while ((c = getcx(fp)) != EOF)
                putchar(c);    
        }
    }
    end = clock();
    printf("=========================================================================================================\n");
    printf("The above code block was executed in %.7f seconds\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));

    return 0;
}