#include<stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

int printrange(char s[], char start, char finish) {
    int i, j;
    j = 0;
    if (start < finish &&
        ( (isdigit(start) && isdigit(finish)) ||
          (isupper(start) && isupper(finish)) ||
          (islower(start) && islower(finish)) )
        )
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
    char buf[30];
    for (i = 0; s[i] != '\0'; i++) {
        if (
            (isdigit(s[i]) || isalpha(s[i])) &&
            s[i + 1] == '-' && s[i + 2] != '\0' &&
            (isdigit(s[i + 2]) || isalpha(s[i + 2])) )
        {
            printrange(buf, s[i], s[i + 2]);
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
    char s1[200] = "---a-J-";
    char s2[MAX_ARRAY_SIZE];
    pars(s1, s2);
    printf("S2 - %s\n", s2);
}
#include<stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

int printrange(char s[], char start, char finish) {
    int i, j;
    j = 0;
    if (start < finish &&
        ( (isdigit(start) && isdigit(finish)) ||
          (isupper(start) && isupper(finish)) ||
          (islower(start) && islower(finish)) )
        )
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
    char buf[30];
    for (i = 0; s[i] != '\0'; i++) {
        if (
            (isdigit(s[i]) || isalpha(s[i])) &&
            s[i + 1] == '-' && s[i + 2] != '\0' &&
            (isdigit(s[i + 2]) || isalpha(s[i + 2])) )
        {
            printrange(buf, s[i], s[i + 2]);
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
    char s1[200] = "---a-m-0-9-";
    char s2[MAX_ARRAY_SIZE];
    pars(s1, s2);
    printf("%s\n", s2);
}
