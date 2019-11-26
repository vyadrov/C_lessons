#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 30

void strcat_pointer(char *string1, char *string2) {
    string1 += strlen(string1);        
    while (*string2 != '\0') {
        *string1 = *string2;
        string1++;
        string2++;
    }
    *string1 = '\0';    
}

void strcpy_pointer(char *string1, char *string2) {
    while (*string2 != '\0') {
        *string1 = *string2;
        string1++;
        string2++;
    }
    *string1 = '\0';
}

int strcmp_pointer(char *string1, char *string2) {
    while ((*string1 != '\0') && (*string2 != '\0') && (*string1 == *string2)) {
        string1++;
        string2++;
    }
    return *string1 - *string2;
}

int main(void) {

    int result;
    char string1[MAX_SIZE] = "abder";
    char string2[MAX_SIZE] = "der";
    char string3[MAX_SIZE] = "asdf";
    char string4[MAX_SIZE] = "qwer";
    char string5[MAX_SIZE] = "hello";
    char string6[MAX_SIZE] = "hello";
    char string7[MAX_SIZE] = "hEllo";    

    strcat_pointer(string1, string2);
    printf("%s\n", string1);
    strcpy_pointer(string3, string4);
    printf("%s\n", string3);
    result = strcmp_pointer(string5, string6);
    printf("%d\n", result);
    result = strcmp_pointer(string5, string7);
    printf("%d\n", result);
    result = strcmp_pointer(string7, string6);
    printf("%d\n", result);

    return 0;
}