#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 15

void scan(char string1[ARRAY_SIZE], char string2[ARRAY_SIZE]) {
	printf("Please enter any first word:\n");
	scanf("%14s", string1);
	if (strlen(string1) >= ARRAY_SIZE - 1) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }
	printf("Please enter any second word:\n");
	scanf("%14s", string2);	
    if (strlen(string2) >= ARRAY_SIZE - 1) {
        printf("You entered too long number. Please try again\n");
        exit(0);
    }
}

void squeeze(char string1[], char string2[], char result_string[]) {
    int string1_element_index, string2_element_index, result_string_element_index;
    result_string_element_index = 0;
    for (string1_element_index = 0; string1[string1_element_index] != '\0'; string1_element_index++) {
    	for (string2_element_index = 0; string2[string2_element_index] != '\0'; string2_element_index++) {
    		if (string1[string1_element_index] == string2[string2_element_index])
    			break;
    	}
    	if (string1[string1_element_index] != string2[string2_element_index]) {
    		result_string[result_string_element_index] = string1[string1_element_index];
    	  	result_string_element_index++;
    	}    	
    }
    result_string[result_string_element_index] = '\0';
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

