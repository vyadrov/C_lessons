#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

// TODO: remove blank line
// TODO: rename to reverse(char *string)
void reverse_pointer(char *string) {

// TODO: rename char *temp to char *reverse_pointer
    char *temp, temp_symbol;
    
// TODO: remove blank line
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
