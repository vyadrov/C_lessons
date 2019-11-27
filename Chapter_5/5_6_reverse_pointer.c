#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100


void reverse_pointer(char *string) {

    char *temp;
    int i;

    for (temp = string + strlen(string) - 1; string < temp; string++, temp--) {
        i = *string;
        *string = *temp;
        *temp = i;
    }
}

int main(void) {
    
    char string[ARRAY_SIZE] = "abcde";
    reverse_pointer(string);
    printf("%s\n", string);
}