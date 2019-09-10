#include<stdio.h>

int lower(char c) {    
    
    return ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c);
}

int main(void) {
    char c;

    printf("Please enter any uppercase character to convert in lower:\n");
    scanf("%c", &c);
    printf("Your uppercase character after converting in lowercase: %c\n", lower(c));
}