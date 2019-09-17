#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE 30
#define MAX_ARRAY_SIZE_S1 100
#define MAX_ARRAY_SIZE_S2 1000

int is_valid(char start, char finish) {
    return (start < finish &&
            ( (isdigit(start) && isdigit(finish)) ||
              (isupper(start) && isupper(finish)) ||
              (islower(start) && islower(finish)) ));
}

int is_range(char a, char b, char c) {
    return (isalnum(a) &&
            b == '-' && isalnum(c) );
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

void pars(char s[], char s_out[]) {
    int i;
    char buf[BUF_SIZE];
    for (i = 0; s[i] != '\0'; i++) {
        if (is_range(s[i], s[i + 1], s[i + 2]))
        {
            print_range(buf, s[i], s[i + 2]);
            strcat(s_out, buf);
            i+=2;
        }
        else
        {
            buf[0] = s[i];
            buf[1] = '\0';
            strcat(s_out, buf);
        }
    }
}

int main(void) {
    char initial_string[MAX_ARRAY_SIZE_S1] = "---a-ehjkl";
    char expanded_string[MAX_ARRAY_SIZE_S2];
    for (int i = 0; i < MAX_ARRAY_SIZE_S2; i++)
        expanded_string[i] = 0;
    pars(initial_string, expanded_string);
    printf("%s\n", expanded_string);
}
