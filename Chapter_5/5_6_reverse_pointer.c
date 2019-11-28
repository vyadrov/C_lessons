#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

void reverse(char *string) {
    char *reverse_pointer, temp_symbol;    

    for (reverse_pointer = string + strlen(string) - 1; string < reverse_pointer; string++, reverse_pointer--) {
        temp_symbol = *string;
        *string = *reverse_pointer;
        *reverse_pointer = temp_symbol;
    }
}

int main(void) {    
    char string[ARRAY_SIZE] = "abcde";

    printf("String before reverse: %s\n", string);
    reverse(string);
    printf("String after reverse: %s\n", string);
}
