#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define TAB_SIZE 8

void detab(int argc, char *argv[], char *string) {
    int space_amount, symbol, i, j, k;
    int tab_size = TAB_SIZE;
    int tab_stop = 0;
    i = 0;
    j = 0;

    if (argc > 1) {
        j = 1;
        tab_size = atoi(argv[j++]);
    }

    while ((symbol = getchar()) != EOF) {
        if (symbol == '\t') {
            space_amount = tab_size - tab_stop;
            for (k = 0; k < space_amount; k++) {
                string[i] = ' ';
                i++;
            }
            tab_stop = 0;
        } else if (symbol != '\n') {
            string[i] = symbol;
            tab_stop = (tab_stop + 1) % tab_size;
            i++;
        }
        if (tab_stop == 0 && j != 0 && j < argc)
            tab_size = atoi(argv[j++]);
    }
    string[i] = '\0';
}

void entab(int argc, char *argv[], char *string) {
    int symbol, i, j;
    int tab_size = TAB_SIZE;    
    int tab_stop = 0;
    i = 0;
    j = 0;

    if (argc > 1) {
        j = 1;
        tab_size = atoi(argv[j++]);
    }

    while ((symbol = getchar()) != EOF) {
        string[i] = symbol;
        if (symbol == ' ' && tab_stop == tab_size - 1) {
            while (string[i - 1] == ' ')
                i--;
            string[i] = '\t';
            tab_stop = 0;
        } else if (symbol != '\n') {
            tab_stop = (tab_stop + 1) % tab_size;
        }
        if (tab_stop == 0 && j != 0 && j < argc)
            tab_size = atoi(argv[j++]);
        i++;
    }
    string[i] = '\0';
}

int main(int argc, char *argv[]) {
    char string[MAXLEN];

    entab(argc, argv, string);
    printf("%s\n", string);
    detab(argc, argv, string);
    printf("%s\n", string);
    return 0;
}