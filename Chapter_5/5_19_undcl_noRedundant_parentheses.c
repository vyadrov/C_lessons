#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100
enum { NAME, PARENS, BRACKETS };
enum { YES, NO};

void dcl(void);
void dirdcl(void);
void errmsg(char *);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int error_token = NO;
char buf[BUFSIZE];
int bufp = 0;

/* dcl: parse a declarator  */
void dcl(void) {
    int ns;
    
    for (ns = 0; gettoken() == '*';)     /* count *'s    */
        ns++;    
    dirdcl();
    while (ns-- > 0)
        strcat(out, "pointer to ");
}

/* dirdcl: parse a direct declaration */
void dirdcl(void) {
    int type;
    
    if (tokentype == '(' ) {
        dcl();
        if (tokentype != ')') {
            printf("error: missing ) \n");
            error_token == YES;
        }
    }
    else if (tokentype == NAME)
        strcpy(name, token);
    else {
        printf("error: expected name or (dcl) \n");
        error_token == YES;
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out,"function returning ");
        else {
            strcat(out, "array ");
            strcat(out, token);
            strcat(out, " of ");
        }
}

int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char *p = token;
        
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p ='\0';
        return tokentype = BRACKETS;
    } 
    else if (isalpha(c)) {
        for(*p++ = c; isalnum(c = getch());)
            *p++ = c;        
        *p = '\0';        
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}

int main() {
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);    
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
                while ((type = gettoken()) != '\n');
                break;
            }
            else
                printf("invalid input at %s \n", token);
        printf("%s\n", out);
    }
    return 0;
}