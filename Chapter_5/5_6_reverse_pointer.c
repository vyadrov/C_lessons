#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100


void reverse_pointer(char *string) {

    char *temp, temp_symbol;
    

    for (temp = string + strlen(string) - 1; string < temp; string++, temp--) {
        temp_symbol = *string;
        *string = *temp;
        *temp = temp_symbol;
    }
}

int main(void) {
    
    char string[ARRAY_SIZE] = "abcde";

    printf("String before reverse: %s\n", string);
    reverse_pointer(string);
    printf("String after reverse: %s\n", string);
}