#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */
#define OVER_MAXLEN 100000 /* max length for buffering all strings */

char *lineptr[MAXLINES];
char lines[OVER_MAXLEN];

int readlines(char *lineptr[], char lines[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[],int left,int right);
void swap(char *lineptr[], int i, int j);

/* sort input lines */

int main(void) {
    int nlines; /* number of input lines read */
    printf("Please, enter any strings for their sorting and the press Ctrl + D:\n");
    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        printf("========================================\n");
        printf("Strings after sorting:\n");
        printf("========================================\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort \n");
        return 1;
    }
}

int mgetline(char *,int);

/* readlines: read input lines */
int readlines(char *lineptr[], char lines[], int maxlines) {
    int len, nlines;
    char *p = lines;
    char line[MAXLEN];
    nlines = 0;            

    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else
        {           
            line[len - 1] = '\0';            
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;         
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void swap(char *string[], int i, int j) {
    char *temp;

    temp = string[i];
    string[i] = string[j];
    string[j] = temp;
}
/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *lineptr[], int left, int right) {
    int i, last;
    
    if (left >= right)
        return;
    swap(lineptr, left, (left+right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    qsort(lineptr, left, last-1);
    qsort(lineptr, last+1, right);
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