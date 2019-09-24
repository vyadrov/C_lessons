#include <stdio.h>

int strindex(char source_string[], char pattern[])
{
    int i, j, k, right_index;
    right_index = -1;
    for (i = 0; source_string[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && source_string[j] == pattern[k]; j++, k++);
        if (k > 0 && pattern[k] == '\0')
            right_index = i;
    }
    return right_index;
}


int main(void) {
    char pattern[] = "asd";    
    char line[] = "asdfghjkasdrt";
    int found = 0;
    
    found  = strindex(line, pattern);
    printf("Index of rightmost occurence in current pattern is: %d\n", found);
}



