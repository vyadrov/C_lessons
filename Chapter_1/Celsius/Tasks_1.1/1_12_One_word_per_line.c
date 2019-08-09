#include <stdio.h>

#define yes 1
#define no 0

int main() {
    int c, s;

    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\t') && (s == ' ' || s == '\t'))
            continue;
        if ((c == ' ' && c == '\t') && (s != ' ' || s != '\t'))
            putchar('\n');
        if ((c != ' ' && c != '\t') && (s == ' ' || s == '\t'))
            putchar('\n');
        if ((c != ' ' || c != '\t') && (s != ' ' || s != '\t'))
            putchar(c);
        s = c;
    }
}