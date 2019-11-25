#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

int strend(char *string1, char *string2) {

    int length;
    unsigned int string2_size = strlen(string2);
    if (strlen(string1) < string2_size)
        return 0;

    while(*string1 != '\0')
        string1++;
    string1--;

    while(*string2 != '\0')
        string2++;
    string2--;    

    for (length = string2_size; length > 0; length--) {
        if (*string2 == *string1) {
            string1--;
            string2--;
        }
        else
            return 0;
    }    
    return 1;
}

int main(void) {

    int result;
    char string1[MAX_SIZE] = "abder";
    char string2[MAX_SIZE] = "der";    
    char string3[MAX_SIZE] = "dor";    
    char string4[MAX_SIZE] = "pder";   

    result = strend(string1, string2);
    printf("String1 - %s, String2 - %s, result = %d\n", string1, string2, result);
    result = strend(string1, string3);
    printf("String1 - %s, String2 - %s, result = %d\n", string1, string3, result);
    result = strend(string1, string4);
    printf("String1 - %s, String2 - %s, result = %d\n", string1, string4, result);

    return 0;    
}