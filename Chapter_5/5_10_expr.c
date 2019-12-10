#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

void push(double f) {
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void) {
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char *string) {
    if (!(isdigit(string[0]) || string[0] == '.' || (string[0] == '-' && isdigit(string[1]))))
        return string[0];
    return NUMBER;
}

int main(int argc, char *argv[]) {    
    int type;
    double op1, op2;
    char s[MAXOP];

    for (int i = 1; i < argc; i++)
    {
        type = getop(argv[i]);
        switch(type)
        {
                case NUMBER:
                        push(atof(argv[i]));
                        break;
                case '+':
                        push(pop() + pop());
                        break;
                case '*':
                        push(pop() * pop());
                        break;
                case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                case '/':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(pop()/op2);
                        else
                            printf("error:zero divisor\n");
                        break;
                case '%':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(fmod(pop(),op2));
                        else
                            printf("error:zero divisor\n");
                        break;
                case 'c':
                        sp = 0;
                        break;
                case 'd':
                        op2 = pop();
                        push(op2);
                        push(op2);
                        break;
                case 's':
                        op1 = pop();
                        op2 = pop();
                        push(op1);
                        push(op2);
                        break;
                case 't':
                        op2 = pop();
                        printf("\t%-.8g\n", op2);
                        push(op2);
                        break;
                case '\n':
                        printf("\t%-.8g\n", pop());
                        break;
                default:
                        printf("error: unknown command %s\n", s);
                        break;

        }
    }
    printf("\t%-.8g\n", pop());
    return 0;
}