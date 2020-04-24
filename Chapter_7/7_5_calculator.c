#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define NAME 'n'
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

enum operations {
    POWER = 1,
    SIN,
    COS,
    EXP,
    CLEAN,
    DOUBLE,
    SWAP,
    TOP,
    ADD,
    DIFF,
    MOD,
    MULTIPLE,
    DIVIDE
};

#define POWER_STRING "pow"
#define SIN_STRING "sin"
#define COS_STRING "cos"
#define EXP_STRING "exp"
#define CLEAN_STRING "c"
#define DOUBLE_STRING "d"
#define SWAP_STRING "s"
#define TOP_STRING "t"
#define ADD_STRING "+"
#define DIFF_STRING "-"
#define MOD_STRING "\%"
#define MULTIPLE_STRING "*"
#define DIVIDE_STRING "/"

int stackPosition = 0;
double valueStack[MAXVAL];
char bufForUngetch[BUFSIZE];
int freePositionInBuf = 0;

void push(double f) {
    if (stackPosition < MAXVAL)
        valueStack[stackPosition++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

double pop(void) {
    if (stackPosition > 0)
        return valueStack[--stackPosition];

    printf("error: stack empty\n");
    return 0.0;
}

enum operations getOperationCode(char* string) {

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
    else if (strcmp(string, ADD_STRING) == 0) {
        return ADD;
    }
    else if (strcmp(string, DIFF_STRING) == 0) {
        return DIFF;
    }
    else if (strcmp(string, MOD_STRING) == 0) {
        return MOD;
    }
    else if (strcmp(string, MULTIPLE_STRING) == 0) {
        return MULTIPLE;
    }
    else if (strcmp(string, DIVIDE_STRING) == 0) {
        return DIVIDE;
    }
    
    return -1;
}

int main(void) {
    char *type;
    int opcode;
    double operator_1, operator_2, value = 0;
    char string[MAXOP], buf[MAXOP];
    char e = '\0';

    while (scanf("%s%c", string, &e) == 2) {
        if (sscanf(string, " %lf", &value) == 1)
            push(value);
        else if (sscanf(string, "%s", buf)) {
            enum operations opcode = getOperationCode(string);
            switch (opcode) {
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
                printf("\t%-.8g\n", operator_2);
                push(operator_2);
                break;
            case ADD:
                push(pop() + pop());
                break;
            case MULTIPLE:
                push(pop() * pop());
                break;
            case DIFF:
                operator_2 = pop();
                push(pop() - operator_2);
                break;
            case DIVIDE:
                operator_2 = pop();
                if (operator_2 != 0.0)
                    push(pop() / operator_2);
                else
                    printf("error:zero divisor\n");
                break;
            case MOD:
                operator_2 = pop();
                if (operator_2 != 0.0)
                    push(fmod(pop(), operator_2));
                else
                    printf("error:zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", type);
                break;
            }
        }
        if (e != ' ') {
            printf("\t%-.8g\n", pop());
        }
    }
    return 0;
}
