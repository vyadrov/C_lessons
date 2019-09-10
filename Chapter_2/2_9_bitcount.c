#include<stdio.h>

int bitcount(unsigned x) {
    int b;

    for(b = 0; x != 0; x &= x - 1)
        b++;

    return b;
}

void print_binary(unsigned x) {    
    
    for (int i = sizeof(x) * 8 - 1; i >= 0; i--) {
        printf("%d", (x & (1 << i)) >> i);
    }

    printf("\n");

    return;
}

int main(void) {
    unsigned x;

    printf("Please enter any number 'x' in Dec system:\n");
    scanf("%u", &x);
    printf("'x' in Binary system:\n");
    print_binary(x);
    x = bitcount(x);
    printf("Number of 1-bits is:%u\n", x);
}

