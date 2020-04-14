#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    
    printf("Please enter any symbols. It will be prinyed and non-graphic characters will be printed in octal system:\n");
    while((c = getchar()) != EOF) {
        if(iscntrl(c)) {
            printf("\\%03o\n", c);
        } else
        printf("%c", c);
    }
}