#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 30
#define STRINGIFY(x)

void scan(char string1[ARRAY_SIZE], char string2[ARRAY_SIZE]) {
    printf("Please enter any first word:\n");
    scanf("%" STRINGIFY(ARRAY_SIZE) "s", string1);
    fgets(string1, ARRAY_SIZE, stdin);

    if (strlen(string1) >= ARRAY_SIZE) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }

    printf("Please enter any second word:\n");
    scanf("%" STRINGIFY(ARRAY_SIZE) "s", string2);
    fgets(string2, ARRAY_SIZE, stdin); 

    if (strlen(string2) >= ARRAY_SIZE) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }
}

void squeeze(char string1[], char string2[], char result_string[]) {
    int i, j, k;
    k = 0;

    for (i = 0; string1[i] != '\0'; i++) {
        for (j = 0; string2[j] != '\0'; j++) {
            if (string1[i] == string2[j])
                break;
        }
        if (string1[i] != string2[j]) {
            result_string[k] = string1[i];
            k++;
        }       
    }
    result_string[k] = '\0';
}

int main(void) {
    char result_string[ARRAY_SIZE];
    char string1[ARRAY_SIZE];
    char string2[ARRAY_SIZE];

    scan(string1, string2);
    squeeze(string1, string2, result_string);
    printf("Your final string is: %s\n", result_string);

    return 0;
}

