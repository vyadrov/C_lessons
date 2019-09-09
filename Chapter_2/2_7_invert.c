#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n) {
    int k, z;
    
    z = ~(~0 << n); //set "1" to first n bits
    z = z << (p - n + 1); //shift left to p index
    x = x ^ z; // inverting the bits

    return x;

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
    printf("Please enter start position 'p' in number 'x':\n");
    scanf("%u", &p);
    printf("Please enter 'n' bits:\n");
    scanf("%u", &n);
    x = setbits(x, p, n);
    printf("Final number 'x' in Dec system is: %u\n", x);
    printf("Final number 'x' in Binary system:\n");
    print_binary(x);

    return 0;
}