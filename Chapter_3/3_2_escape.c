#include <stdio.h>
#define ARRAY_SIZE 100

void scan(char s[ARRAY_SIZE]) {
    int i = 0;
    printf("Please enter any first word:\n");
    while ((s[i] = getchar()) != EOF) {
        i++;
    }
    s[i] = '\0';
}

void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[j] = '\\';
                t[j + 1] = 'n';
                j++;
                break;
            case '\t':
                t[j] = '\\';
                t[j + 1] = 't';
                j++;
                break;
            default:
                t[j] = s[i];
                break;
        }
        i++;
        j++;
    }
    t[j] = '\0';
}

int main(void) {
    char s[ARRAY_SIZE], t[ARRAY_SIZE];

    scan(s);
    escape(s, t);
    printf("Your final string is: %s\n", t);

    return 0;
}