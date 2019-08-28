#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARRAY_SIZE 15

void scan(char s1[ARRAY_SIZE], char s2[ARRAY_SIZE]) {
	printf("Please enter any first word:\n");
	scanf("%14s", s1);
	if (strlen(s1) >= ARRAY_SIZE - 1) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }
	printf("Please enter any second word:\n");
	scanf("%14s", s2);	
    if (strlen(s2) >= ARRAY_SIZE - 1) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }
}

void squeeze(char s1[], char s2[], char s_out[]) {
    int i, j, k;
    k = 0;
    for (i = 0; s1[i] != '\0'; i++) {
    	for (j = 0; s2[j] != '\0'; j++) {
    		if (s1[i] == s2[j])
    			break;
    	}
    	if (s1[i] != s2[j]) {
    		s_out[k] = s1[i];
    	  	k++;
    	}    	
    }
    s_out[k] = '\0';
}

int main(void) {
	char s_out[ARRAY_SIZE];

    char s1[ARRAY_SIZE];
    char s2[ARRAY_SIZE];
    scan(s1, s2);
    squeeze(s1, s2, s_out);
    printf("Your final string is: %s\n", s_out);

    return 0;
}

