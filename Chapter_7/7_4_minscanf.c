#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define MAXCHARS 100

void minscanf(char *fmt,...) {
    va_list ap;
    char *p,*sval;
    int *ival;
    unsigned *uval;
    float *dval;
    int width;
    char format[MAXCHARS];

    va_start(ap, fmt);
    
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            continue;
        }
        if (isdigit(*++p))
            width = atoi(p);
        while (isdigit(*p))
            p++;
        
        switch(*p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, float *);
                scanf("%f", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                sprintf(format, "%%%ds", width);
                scanf(format, sval);
                break;
            case 'o':
                uval = va_arg(ap, unsigned *);
                scanf("%o", uval);
                break;
            default:
                break;
        }
    }
    va_end(ap);
}

int main() {
    
    
    int scan;
    float scan1;
    char scan2[MAXCHARS];
    unsigned scan3;
    printf("Please enter any number in dec system: \n");
    minscanf("%d", &scan);
    printf("Your scanned number in dec system is: %d\n", scan);
    printf("Please enter any float number: \n");
    minscanf("%f", &scan1);
    printf("Your scanned number is: %f\n", scan1);
    printf("Please enter any word: \n");
    minscanf("%7s", scan2);
    printf("Your scanned word is: %s\n", scan2);
    printf("Please enter any number in oct system:\n");
    minscanf("%o", &scan3);
    printf("Your scanned number is: %o\n", scan3);
  
  return 0;
}