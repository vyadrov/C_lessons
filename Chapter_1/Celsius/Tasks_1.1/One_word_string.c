#include <stdio.h>

#define yes 1
#define no 0

int main() {
    int c, vi;
    vi = no;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            vi = yes;
        if (vi == yes) {
            c = '\n';
            vi = no;
        }
        putchar(c);
    }
}