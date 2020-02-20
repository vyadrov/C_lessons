#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))
#define MAXWORD 100
#define BUFSIZE 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatite", 0,
    "while", 0
};

char buf[BUFSIZE];
int bufp = 0;

int mygetword(char *, int);
int binsearch(char *, struct key*, int);

int main(int argc, char *argv[]) {   
    int n;
    char word[MAXWORD];

    while (mygetword(word, MAXWORD) != EOF)
       if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
}

int binsearch(char *word, struct key keytab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, keytab[mid].word)) < 0 )
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int mygetword(char *word, int lim) {
    int symbol;
    int getch(void);
    void ungetch(int);
    char *pointer_w = word;
    int temp;

    while (isspace(symbol = getch()))
        ;
    if (symbol != EOF)
        *pointer_w++ = symbol;
    if (!isalpha(symbol)) {
        if (symbol == '_') {
            while (isspace(symbol = getch()))
                ; 
        }
        else if (symbol == '#') {
            while (isspace(symbol = getch())) 
                ;
        }
        else if (symbol == '/') {
            if ((symbol = getch()) == '/')
                while (isspace(symbol = getch()) && symbol != '\n')
                ;
            else if ((symbol = getch()) == '*') {
                temp = symbol;
                while (isspace(symbol = getch()) && !(symbol == '/' && temp == '*'))
                    temp = symbol;                
            }                        
        }             
        *pointer_w = '\0';
        return symbol;
    }
    
    for ( ; --lim > 0; pointer_w++)
        if (!isalnum(*pointer_w = getch()) && *pointer_w != '_') {
            ungetch(*pointer_w);
            break;            
        }
    *pointer_w = '\0';
    return word[0];
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int symbol)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
        else buf[bufp++] = symbol;
}