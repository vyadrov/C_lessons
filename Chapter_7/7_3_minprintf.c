#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void minprintf(char *fmt,...) {
    va_list ap;
    char *p,*sval;
    int ival;
    unsigned uval;
    double dval;
    int width, accuracy;

    va_start(ap, fmt);
    
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        if (isdigit(*++p))
            width = atoi(p);
        while (isdigit(*p))
            p++;  
        if (*p == '.'){
            if (isdigit(*++p))
                accuracy = atoi(p);
        }

        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%*.*f", width, accuracy, dval);
                break;
            case 's':
                for(sval = va_arg(ap,char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'o':
                uval = va_arg(ap, unsigned);
                printf("%o", uval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

int main(void) {
    double dval = 5.87878787;
    minprintf("%4.2f\n", dval);
    return 0;
}