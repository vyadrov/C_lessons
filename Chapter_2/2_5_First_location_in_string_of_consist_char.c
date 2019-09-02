#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 30

void scan(char string1[ARRAY_SIZE], char string2[ARRAY_SIZE]) {
    printf("Please enter any first word:\n");
    fgets(string1, ARRAY_SIZE, stdin);

    if (strlen(string1) >= ARRAY_SIZE - 1) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }

    printf("Please enter any second word:\n");
    fgets(string2, ARRAY_SIZE, stdin);

    if (strlen(string2) >= ARRAY_SIZE - 1) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }
}

int comparison_of_characters(char string1[], char string2[]) {
    int i, j;

    for (i = 0; string1[i] != '\0'; i++) {
        for (j = 0; string2[j] != '\0'; j++) {
            if (string1[i] == string2[j] && string1[i] !='\n') {
                return i;
            }
        }
    }
    return -1;
}

int main(void) {
    char string1[ARRAY_SIZE];
    char string2[ARRAY_SIZE];

    scan(string1, string2);

    int result = comparison_of_characters(string1, string2);
    if(result == -1)
        printf("No matches\n");
    else
        printf("Location of first consist symbol between string1 and string2 is: %d, symbol - '%c', ASCII code = %d\n", result + 1, string1[result], string1[result]);

    return 0;
}
