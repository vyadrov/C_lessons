#include<stdio.h>

#define ARRAY_SIZE 12


int binsearch(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = 0;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;   
    }
    if (x == v[low])
        return low;
    else
        return - 1;   
}

int main(void) {
    int a;
    int array[ARRAY_SIZE] = {2, 3, 4, 5, 9, 13, 16, 19, 20, 25, 30, 45};
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Please enter number 'x' to find in array:\n");
    scanf("%d", &a);
    printf("%d",binsearch(a,array,ARRAY_SIZE));

    return 0;
}