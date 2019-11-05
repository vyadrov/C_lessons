#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

static void reverse_recursive_internal(char string[], int start) {
    
    int end, temp;
    end = strlen(string) - 1 - start;

    if (start < end) {
        temp = string[start];
        string[start] = string[end];
        string[end] = temp;

        reverse_recursive_internal(string, ++start);
    }
}
void reverse_recursive(char string[]) {
    reverse_recursive_internal(string, 0);
}

int main(void) {

    char string[ARRAY_SIZE] = "5423694";

    reverse_recursive(string);
    printf("%s\n", string);
}