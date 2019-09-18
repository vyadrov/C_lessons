#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define ARRAY_SIZE 100


void reverse(char s[]) {
    int i, j, k;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        k = s[i];
        s[i] = s[j];
        s[j] = k;
    }
}

void itoa(int n, char s[]) {
    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    int n;
    char s[ARRAY_SIZE];
    itoa(-2147483648, s);
    printf("%s\n", s);
}