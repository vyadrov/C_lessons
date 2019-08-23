#include <stdio.h>
#define ARRAY_SIZE 10



int htoi(char s[ARRAY_SIZE]) {
	int input_digit, array_element_index, coefficient;
	coefficient = 0;
	for (array_element_index = 0; (input_digit = s[array_element_index]) != '\0'; ++array_element_index) {
        coefficient = coefficient * 16;
        if (input_digit == '0') {
            input_digit = s[++array_element_index];
            if (input_digit != 'x' && input_digit != 'X')
                --array_element_index;
            else if (s[array_element_index] == 'x' && s[array_element_index] == 'X')
                ++array_element_index;                 
        }
        else if (input_digit >= '0' && input_digit <= '9')
            coefficient = coefficient + input_digit - '0';
        else if (input_digit >= 'a' && input_digit <= 'f')
            coefficient = coefficient + 10 + (input_digit - 'a');
        else if (input_digit >= 'A' && input_digit <= 'F')
            coefficient = coefficient + 10 + (input_digit - 'A');
        else
            return coefficient;
    }
    return coefficient;
}

void scan_hex_number(char s[ARRAY_SIZE]) {
	int array_element_index, input_digit, count;
    count = 0;
	printf("Please enter any Hex number:\n");
	for (array_element_index = 0; (input_digit = getchar()) != '\n'; array_element_index++){
		s[array_element_index] = input_digit;
        count++;
        if (count > ARRAY_SIZE) {
            printf("You entered too long number. Please try again\n");
        return;
        }
    }    
	s[array_element_index] = '\0';
	printf("%s in Dec system is: %d\n", s, htoi(s));
}

int main (void) {
	char s[ARRAY_SIZE];
	scan_hex_number(s);
	htoi(s);
}