#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    clock_t start, end;
    FILE *fp;
    void filecopy(FILE *, FILE *);

    if (argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            start = clock();
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: Can't open file %s\n", *argv);
                return 1;
            }
            else {
                filecopy(fp, stdout);
                fclose(fp);
                end = clock();
                printf("=========================================================================================================\n");
                printf("The above code block was executed in %.7f seconds\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
            }

    return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}