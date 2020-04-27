#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void filecmp(FILE* fp1, FILE* fp2) {
    int error = 0, pos = 0, line = 1;
    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    while (ch1 != EOF && ch2 != EOF) {
        pos++;
        if (ch1 == '\n' && ch2 == '\n') {
            line++;
            pos = 0;
        }
        if (ch1 != ch2) {
            error++;
            printf("Line Number: %d\tError Position: %d\nCharacter in first file is: %c\t Character in second file is: %c\n", line, pos, ch1, ch2);
        }
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }
    printf("===============================================================\n");
    printf("Total number of errors: %d\t\n", error);
}

int main(int argc, char* argv[]) {
    FILE* fp1, * fp2;
    void filecmp(FILE*, FILE*);

    if (argc != 3)
    {
        /* no args; copy standard input */
        printf("Please provide two files:\n");
        return 1;
    }
    else        
        if ((fp1 = fopen(argv[1], "r")) == NULL) {
            printf("cat: can't open %s\n", *argv);
            return 1;
        }

        if ((fp2 = fopen(argv[2], "r")) == NULL) {
            printf("cat: can't open %s\n", *argv);
            fclose(fp1);
            return 1;
        }
        filecmp(fp1, fp2);
        fclose(fp1);
        fclose(fp2);        

    return 0;
}