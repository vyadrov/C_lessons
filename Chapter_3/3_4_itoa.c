#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define ARRAY_SIZE 100


void reverse(char string[]) {
    int i, j, temp;

    for (i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

void itoa(int number, char string[]) {
    int i, sign;

    sign = number;
    i = 0;

    do {
        string[i++] = abs(number % 10) + '0';
    } while ((number /= 10) != 0);
    if (sign < 0)
        string[i++] = '-';
    string[i] = '\0';
    reverse(string);
}

int main(void) {
    char string[ARRAY_SIZE];
    itoa(-2147483648, string);
    printf("%s\n", string);
}