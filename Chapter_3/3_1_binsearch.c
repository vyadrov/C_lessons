#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000


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
    if (x == v[high])
        return high;
    else
        return - 1;   
}

int classic_search_method(int x, int v[], int n) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (x == v[i])
            return i;
    }
        return -1;

}

int main(void) {
    int a;
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i * 2;
        //printf("%d ", array[i]);
    }
    printf("\n");
    printf("Please enter number 'x' to find in array:\n");
    scanf("%d", &a);
    clock_t tic = clock();
    printf("Index of 'x' in array is: %d\n",binsearch(a,array,ARRAY_SIZE));
    clock_t toc = clock();
    printf("Elapsed: %f seconds for binsearch method\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    printf("Please enter number 'x' to find in array:\n");
    scanf("%d", &a);
    clock_t pic = clock();
    printf("Index of 'x' in array is: %d\n", classic_search_method(a, array, ARRAY_SIZE));
    clock_t poc = clock();
    printf("Elapsed: %f seconds for classic search method\n", (double)(poc - pic) / CLOCKS_PER_SEC);

    return 0;
}