#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define BUFSIZE 100

int getch(void);
void ungetch(int);

int getfloat(float *nump) {

    int ch, sign;
    float power;

    while (isspace(ch = getch()))
    ;
    
    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-' && ch != '.') {
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
    
    
    for (*nump = 0.0; isdigit(ch); ch = getch())
        *nump = 10.0 * *nump + (ch - '0');
    if (ch == '.')
        ch = getch();
    for (power = 1.0; isdigit(ch); ch = getch()) {
        *nump = 10.0 * *nump + (ch - '0');
        power *= 10.0;
    }
    
    *nump *= sign/power;
        
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

    float res = 0.0;

    getfloat(&res);
    printf("Result = %f, Buffer = %s\n", res, buf);

    return 0;
}