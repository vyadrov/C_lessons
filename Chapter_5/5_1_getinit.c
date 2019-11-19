#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define BUFSIZE 100

int getch(void);
void ungetch(int);

int getint(int *nump) {

    int ch, sign;

    while (isspace(ch = getch()))
    ;
    
    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-') {
        ungetch(ch);
        return 0;
    }
    
    sign = (ch == '-') ? -1 : 1;

    if (ch == '+' || ch == '-') {
        ch = getch();
        if (!isdigit(ch)) {
            ungetch(ch);
            ungetch(sign == -1 ? '-' : '+');          
            return ch;
        }
    }
    
    
    for (*nump = 0; isdigit(ch); ch = getch())
        *nump = 10 * *nump + (ch - '0');
    
    *nump *= sign;
        
    if(ch != EOF)
        ungetch(ch);
    return ch;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int ch) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = ch;
}

int main(void) {

    int res = 0;

    getint(&res);
    printf("Result = %d, Buffer = %s\n", res, buf);

    return 0;
}