#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESPERPAGE 5

void printfpages(FILE *, FILE *);

int main(int argc, char *argv[]) {
    FILE *fp;
    char *prog = argv[0];

    if (argc != 3) {
        printf("Please provide two files:\n");
        return 1;
    }
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                fprintf(stdout, "\n\nPrinting File: %s\n\n", *argv);
                printfpages(fp, stdout);
                fclose(fp);
            }
    return 0;
}

void printfpages(FILE *ifp, FILE *ofp) {
    int c;
    int line = 0;
    int page = 1;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
        if (c == '\n') {
            line += 1;
            if (line == LINESPERPAGE) {
                fprintf(stdout, "\nEnd of Page %d\n\n", page);
                page += 1;
                line = 0;
            }
        }        
    }
    if (c == EOF && line != 0) {
        fprintf(stdout, "\nEnd of Page %d\n\n", page);
    }
}