#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))
#define MAXWORD 100
#define BUFSIZE 100
#define CHAR_LEN_DEFAULT 6
#define YES      1
#define NO       0 

char *noise_words[] = {
    "the",
    "and",
    "a",
    "an",
    "some",
    "if",
    "then",
    "else",
    NULL,
};

struct tnode {  //the tree node
    char *word; //points to text
    int match; //sign matches
    struct tnode *left; //left child
    struct tnode *right; //right child
    struct list *lineNumbers;
};

char buf[BUFSIZE];
int bufp = 0;

struct tnode *addtree(struct tnode *, char *, int);
int compare(char *, struct tnode *);
struct tnode *talloc(void);
char *mstrdup(char *);
void treeprint(struct tnode *);
int mygetword(char *, int, int *);
void mytolowerstr(char *word);
int is_noise_word(char *word);

struct tnode *addtree(struct tnode *points, char *stored_word, int lineNumber) {
    int cond;

    if (points == NULL) { /* new word */
        points = talloc();
        points->word = mstrdup(stored_word);
        points->match = 1;
        points->lineNumbers = NULL;
        pushBack(&points->lineNumbers, lineNumber);
        points->left = points->right = NULL;
    }
    else if ((cond = compare(stored_word, points)) == 0) {
        points->match++;
        pushBack(&points->lineNumbers, lineNumber);
    }
    else if (cond < 0)
        points->left = addtree(points->left, stored_word, lineNumber);
    else
        points->right = addtree(points->right, stored_word, lineNumber);
    return points;
}

int compare(char *word, struct tnode *points) {
    int i;
    char *temp = points->word;
    for (i = 0; *word == *temp; i++, word++, temp++)
        if (*word == '\0')
            return 0;
    return *word - *temp;
}

void treeprint(struct tnode *points) {
    if (points != NULL) {
        treeprint(points->left);
        printf("%10s\t", points->word);
        printLinkedList(points->lineNumbers);
        treeprint(points->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mstrdup(char *s) {
    char *points;
    points = (char *) malloc(strlen(s) + 1);
    if (points != NULL)
        strcpy(points, s);
    return points;
}

int mygetword(char *word, int lim, int *line) {
    int symbol;
    int getch(void);
    void ungetch(int);
    char *pointer_w = word;
    int temp;

    while (isspace(symbol = getch()))
        if (symbol == '\n') {
            *line = *line + 1;
        }
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

void mytolowerstr(char *word) {
    while (*word != '\0') {
        *word = tolower(*word);
        word++;
    }
}

int is_noise_word(char *word) {    
    for (int i = 0; noise_words[i] != NULL; i++)
        if (strcmp(word, noise_words[i]) == 0)
            return 1;
    return 0;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int symbol) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
        else buf[bufp++] = symbol;
}

int main(int argc, char *argv[]) {   
    struct tnode *root;
    char word[MAXWORD];
    int length, i, line;
    i = 0;
    line = 1;
    root = NULL;    
    
    if (argc == 1 || argc > 2) {        
        length = CHAR_LEN_DEFAULT;
    }
    else if (argc > 1) {
        i = 1;
        length = abs(atoi(argv[i++]));
    }

    printf("Please enter any words which will be sorted and counted in first %d characters and after that press Ctrl + D:\n", length);        

    while (mygetword(word, MAXWORD, &line) != EOF) {
       if (isalpha(word[0]) && strlen(word) >= length) {
            mytolowerstr(word);
            if (!is_noise_word(word))
                root = addtree(root, word, line);                
       }
    }
    printf("Result in alphabetical order:\n");
    treeprint(root);
    return 0;
}