#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10000
#define DEFLINES 10

int mgetline(char *line, int lim);

char *string_pointers[MAXLEN];
int nlines;

void readlines(char string[]) {
    int i, len, symbol;
    char line[MAXLEN];
    char *p = string;
    nlines = 0;

    while (len = mgetline(line, MAXLEN)) {        
        line[len - 1] = '\0';
        strcpy(p, line);
        string_pointers[nlines++] = p;
        p += len;
    }
}

int mgetline(char *line, int lim) {
    int symbol;
    char *temp = line;

    while (--lim > 0 && (symbol = getchar()) != EOF && symbol != '\n')
        *line++ = symbol;
    if (symbol == '\n')
        *line++ = symbol;
    *line = '\0';
    return line - temp;
}

void print_out_lines(int out_nlines) {
    if (nlines < out_nlines) {
        out_nlines = nlines;
    }
    for (out_nlines = nlines - out_nlines; out_nlines < nlines; out_nlines++) {
        printf("%s\n", string_pointers[out_nlines]);
    }
}

int main(int argc, char *argv[]) {
    char string[MAXLEN];
    printf("Please, enter any strings and the press Ctrl + D:\n");
    printf("========================================\n");
    readlines(string);
    int out_nlines;
    out_nlines = DEFLINES;    

    if (argc > 1) {
        if (argv[1][0] == '-') {
            out_nlines = -atoi(argv[1]);
        }        
    }
    printf("========================================\n");
    printf("Your last %d strings:\n", out_nlines);
    printf("========================================\n");
    print_out_lines(out_nlines);
}