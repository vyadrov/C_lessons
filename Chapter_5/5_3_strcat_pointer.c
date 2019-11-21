#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

void strcat_pointer(char *str1, char *str2) {
    while(*str1 != '\0')
        str1++;

    while((*str1 = *str2) != '\0') {
        str1++;
        str2++;
    }
}

int main(void) {

    char str1[MAX_SIZE] = "abcder";
    char str2[MAX_SIZE] = "qwe";    

    strcat_pointer(str1, str2);
    printf("%s\n", str1);

    return 0;
}