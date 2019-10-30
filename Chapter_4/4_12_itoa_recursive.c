#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int itoa (int number, char string[]) {
    
    int i = 0;
    if (number < 0) {
        putchar ('-');
        number = -number;
    }

    if (number / 10) {
        i = itoa(number / 10, string);
    }

    string[i++] = abs(number) % 10 + '0';
    string[i] = '\0';
    return i;
}


int main(void) {

    int number = 542;
    char string[ARRAY_SIZE];

    itoa(number, string);
    printf("Your final string is: %s\n", string);
}