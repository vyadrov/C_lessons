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

void itob(int number, char string[], int base) {
    int i, sign;

    sign = number;
    i = 0;

    do {
        if (number % base <= 9)
            string[i++] = (number % base) + '0';
        else
            string[i++] = (number % base) + 'A' - 10;
    } while ((number /= base) != 0);
    if (sign < 0)
        string[i++] = '-';
    string[i] = '\0';
    reverse(string);
}

int main(void) {
    char string[ARRAY_SIZE];
    itob(36, string, 16);
    printf("%s\n", string);
}