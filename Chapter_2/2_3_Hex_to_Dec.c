#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 11

long htoi(char s[ARRAY_SIZE]) {
    long input_digit, array_element_index, coefficient;
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
    long input_digit;

    printf("Please enter any Hex number:\n");
    scanf("%10s", s);

    input_digit = htoi(s);

    if (strlen(s) >= ARRAY_SIZE- 1) {
        printf("You entered too long number. Please try again\n");
    } else
        printf("%s in Dec system is: %ld\n", s, input_digit);

}

int main (void) {
    char s[ARRAY_SIZE];
    scan_hex_number(s);
    htoi(s);
}