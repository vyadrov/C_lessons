#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE 30
#define MAX_INITIAL_STRING_SIZE 100
#define MAX_EXPANDED_STRING_SIZE 1000

int is_valid(char start, char finish) {
    return (start < finish &&
            ( (isdigit(start) && isdigit(finish)) ||
              (isupper(start) && isupper(finish)) ||
              (islower(start) && islower(finish)) ));
}

int is_range(char from, char range_symbol, char to) {
    return (isalnum(from) &&
            range_symbol == '-' && isalnum(to) );
}

int print_range(char s[], char start, char finish) {
    int i, j;
    j = 0;
    if (is_valid(start, finish))
    {
        for (i = start; i <= finish; i++)
        {
            s[j] = (char) i;
            j++;
        }
        s[j] = '\0';
    }
    else
    {
        s[0] = start;
        s[1] = '-';
        s[2] = finish;
        s[3] = '\0';
    }
}

void pars(char s_in[], char s_out[]) {
    int i;
    char buf[BUF_SIZE];
    for (i = 0; s_in[i] != '\0'; i++) {
        if (is_range(s_in[i], s_in[i + 1], s_in[i + 2]))
        {
            print_range(buf, s_in[i], s_in[i + 2]);
            strcat(s_out, buf);
            i+=2;
        }
        else
        {
            buf[0] = s_in[i];
            buf[1] = '\0';
            strcat(s_out, buf);
        }
    }
}

int main(void) {
    char initial_string[MAX_INITIAL_STRING_SIZE] = "---a-ehjkl";
    char expanded_string[MAX_EXPANDED_STRING_SIZE];
    for (int i = 0; i < MAX_EXPANDED_STRING_SIZE; i++)
        expanded_string[i] = 0;
    pars(initial_string, expanded_string);
    printf("%s\n", expanded_string);
}
