#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000   /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */
#define OVER_MAXLEN 100000 /* max length for buffering all strings */

char *lineptr[MAXLINES];
char lines[OVER_MAXLEN];

int readlines(char *lineptr[], char lines[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[],int left,int right, int (*comp)(const char *,const char *));
void swap(char *lineptr[], int i, int j);
int numcmp (const char *string1, const char *string2);
void reverse(char *lineptr[]);
int mgetline(char *,int);
int ignore_case_flag;

/* sort input lines */

int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    int numeric_flag = 0;
    int reverse_flag = 0;
    ignore_case_flag = 0;
    printf("Please, enter any strings for their sorting and the press Ctrl + D:\n");

    for (int i = 1; i < argc; i++) {
        if (argc > 1 && strcmp(argv[i], "-n") == 0)
            numeric_flag = 1;
        if (argc > 1 && strcmp(argv[i], "-r") == 0)
            reverse_flag = 1;
        if (argc > 1 && strcmp(argv[i], "-f") == 0)
            ignore_case_flag = 1;
    }    

    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
        myqsort(lineptr, 0, nlines - 1, (int (*) (const char *, const char *))(numeric_flag ? numcmp : strcmp));
        if (reverse_flag == 1) {        
            reverse(lineptr);
        }

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

char *lowercase(char *input){
    char *result = strdup(input);
    for (int i = 0; result[i]; i++)
        result[i] = tolower(result[i]);
    return result;
}

/* myqsort: sort v[left] ... v[right] into increasing order */
void myqsort(char *lineptr[], int left, int right, int (*comp)(const char *, const char *)) {
    int i, last;
    
    if (left >= right)
        return;
    swap(lineptr, left, (left+right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++){        
        char *one = ignore_case_flag ? lowercase(lineptr[i]) : lineptr[i];
        char *two = ignore_case_flag ? lowercase(lineptr[left]) : lineptr[left];
        if ((*comp)(one, two) < 0)
            swap(lineptr, ++last, i);
    }
    swap(lineptr, left, last);
    myqsort(lineptr, left, last - 1, comp);
    myqsort(lineptr, last+1, right, comp);
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

int numcmp(const char *string1, const char *string2) {
    double v1, v2;

    v1 = atof(string1);
    v2 = atof(string2);

    if(v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void reverse(char *lineptr[]) {
    int i, j, nlines;
    char *temp;

    for (i = 0, j = nlines - 1; i < j; i++, j--) {
        temp = lineptr[i];
        lineptr[i] = lineptr[j];
        lineptr[j] = temp;
    }
}
