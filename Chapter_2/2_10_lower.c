#include<stdio.h>

int lower(char c) {    
    
    return (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c) : -1);
}

int main(void) {
    char c;

    int ret = -1;
    while(ret == -1) {
        printf("Please enter any uppercase character to convert in lower:\n");
        scanf("%c[^\n]", &c);        
        if ((ret = lower(c)) == -1)
            printf("It's not a letter, Try again.\n");
        else
            printf("Your uppercase character after converting in lowercase: %c\n", ret);
    }
}