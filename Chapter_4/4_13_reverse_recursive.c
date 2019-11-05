#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int reverse_recursive(char string[], int start) {
    
    int end, temp;
    end = strlen(string) - 1 - start;

    if (start < end) {
        temp = string[start];
        string[start] = string[end];
        string[end] = temp;

        reverse_recursive(string, ++start);
    }
}

int main(void) {

    char string[ARRAY_SIZE] = "5423694";

    reverse_recursive(string, 0);
    printf("%s\n", string);
}