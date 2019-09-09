#include <stdio.h>

#define N 32

unsigned setbits(unsigned x, unsigned n) {
    int left_shift, right_shift, right_rotate_result;
    
    left_shift = x << N - n; //shift first n bits to left
    right_shift = x >> n; //shift other bits to right
    right_rotate_result = left_shift | right_shift; // merge "a" and "y"

    return right_rotate_result;

}

void print_binary(unsigned x) {    
    
    for (int i = sizeof(x) * 8 - 1; i >= 0; i--) {
        printf("%d", (x & (1 << i)) >> i);
    }

    printf("\n");

    return;
}

int main() {
    unsigned x, p, n;

    printf("Please enter any number 'x' in Dec system:\n");
    scanf("%u", &x);
    printf("'x' in Binary system:\n");
    print_binary(x);
    printf("Please enter 'n' bits:\n");
    scanf("%u", &n);
    x = setbits(x, n);
    printf("Final number 'x' in Dec system is: %u\n", x);
    printf("Final number 'x' in Binary system:\n");
    print_binary(x);

    return 0;
}