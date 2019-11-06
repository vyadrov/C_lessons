#include <stdio.h>

#define swap(t, x, y) {t temp; \
                    temp = x; \
                    x = y; \
                    y = temp; }

int main(void) {

    char x, y;
    x = 'a';
    y = 'b';

    printf("Befor swap: 'x' = %c\t 'y' = %c\n", x, y);
    swap(char, x, y);
    printf("After swap: 'x' = %c\t 'y' = %c\n", x, y);
}