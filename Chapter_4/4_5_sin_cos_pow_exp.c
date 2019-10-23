#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <string.h>

#define NAME 'n'
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

#define POWER 1
#define SIN 2
#define COS 3
#define EXP 4
#define CLEAN 5
#define DOUBLE 6
#define SWAP 7
#define TOP 8

#define POWER_STRING "pow"
#define SIN_STRING "sin"
#define COS_STRING "cos"
#define EXP_STRING "exp"
#define CLEAN_STRING "c"
#define DOUBLE_STRING "d"
#define SWAP_STRING "s"
#define TOP_STRING "t"

int stackPosition = 0;
double valueStack[MAXVAL];
char bufForUngetch[BUFSIZE];
int freePositionInBuf = 0;

void push(double f) {
    if(stackPosition < MAXVAL)
        valueStack[stackPosition++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void) {
    if(stackPosition>0)
        return valueStack[--stackPosition];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char string[])
{
    int i,c, temp = -1;

    while((string[0] = c = getch()) == ' ' || c =='\t')
        ;
    string[1] = '\0';
    if (!(isdigit(c) || c == '.' || (c == '-' && (isdigit(temp = getch()))))){
        if (temp > 0){
            ungetch(temp);
            temp = -1;
        }

        if (isalpha(c)){
            i = 0;
            while(isalpha(string[++i] = c = getch()))
                ;
            ungetch(c);
            string[i] = '\0';
            return NAME;
        }

        return c;
    }
    else if (temp > 0){
        ungetch(temp);
        temp = -1;
    }
    i = 0;
    if (c == '-')
        string[++i] = c = getch();

    if(isdigit(c))
        while(isdigit(string[++i] = c = getch()))
            ;

    if(c=='.')
        while(isdigit(string[++i] = c = getch()))
            ;
    
    string[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void) {
    return (freePositionInBuf > 0) ? bufForUngetch[--freePositionInBuf] : getchar();
}

void ungetch(int c) {
    if(freePositionInBuf >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        bufForUngetch[freePositionInBuf++] = c;
}

int getOperationCode(char* string) {
    double operator_1, operator_2;
    if (strcmp(string, POWER_STRING) == 0) {
        return POWER;
    }
    else if (strcmp(string, SIN_STRING) == 0) {
        return SIN;
    }
    else if (strcmp(string, COS_STRING) == 0) {
        return COS;
    }
    else if (strcmp(string, EXP_STRING) == 0) {
        return EXP;
    }
    else if (strcmp(string, CLEAN_STRING) == 0) {
        return CLEAN;
    }
    else if (strcmp(string, DOUBLE_STRING) == 0) {
        return DOUBLE;
    }
    else if (strcmp(string, SWAP_STRING) == 0) {
        return SWAP;
    }
    else if (strcmp(string, TOP_STRING) == 0) {
        return TOP;
    }
    return -1;
}
    

int main(void) {
    int type, opcode;
    double operator_1, operator_2;
    char string[MAXOP];

    while((type = getop(string)) != EOF)
    {
        switch(type)
        {
                case NUMBER:
                        push(atof(string));
                        break;
                case NAME:
                        opcode = getOperationCode(string);
                        switch (opcode){
                            case POWER:
                                    operator_2 = pop();
                                    push(pow(pop(), operator_2));
                                    break;
                            case SIN:
                                    push(sin(pop()));
                                    break;
                            case COS:
                                    push(cos(pop()));
                                    break;
                            case EXP:
                                    operator_2 = pop();
                                    push(exp(pop()));
                                    break;
                            case CLEAN:
                                    stackPosition = 0;
                                    break;
                            case DOUBLE:
                                    operator_2 = pop();
                                    push(operator_2);
                                    push(operator_2);
                                    break;
                            case SWAP:
                                    operator_1 = pop();
                                    operator_2 = pop();
                                    push(operator_1);
                                    push(operator_2);
                                    break;
                            case TOP:
                                    operator_2 = pop();
                                    printf("\t%-.8g\n",operator_2);
                                    push(operator_2);
                                    break;
                            default:
                                    printf("Unknown named operation\n");
                                    break;
                        }
                        break;
                case '+':
                        push(pop()+pop());
                        break;
                case '*':
                        push(pop()*pop());
                        break;
                case '-':
                        operator_2 = pop();
                        push(pop()-operator_2);
                        break;
                case '/':
                        operator_2 = pop();
                        if(operator_2 != 0.0)
                            push(pop()/operator_2);
                        else
                            printf("error:zero divisor\n");
                        break;
                case '%':
                        operator_2 = pop();
                        if(operator_2 != 0.0)
                            push(fmod(pop(),operator_2));
                        else
                            printf("error:zero divisor\n");
                        break;
                
                case '\n':
                        printf("\t%-.8g\n",pop());
                        break;
                default:
                        printf("error: unknown command %s\n",string);
                        break;

        }
    }
    return 0;
}