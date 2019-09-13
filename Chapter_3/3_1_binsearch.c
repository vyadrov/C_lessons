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
    int a, b, c;
    a = 2;
    b = ARRAY_SIZE / 2;
    c = ARRAY_SIZE - 1;
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
        //printf("%d ", array[i]);
    }
    clock_t tic = clock();
    printf("Index of %d in array is: %d\n",a, binsearch(a,array,ARRAY_SIZE));
    clock_t toc = clock();
    printf("Elapsed: %f seconds for binsearch method\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    clock_t pic = clock();
    printf("Index of %d in array is: %d\n", a, classic_search_method(a, array, ARRAY_SIZE));
    clock_t poc = clock();
    printf("Elapsed: %f seconds for classic search method\n", (double)(poc - pic) / CLOCKS_PER_SEC);
    printf("==============================================================\n");
    clock_t sic = clock();
    printf("Index of %d in array is: %d\n",b, binsearch(b, array, ARRAY_SIZE));
    clock_t soc = clock();
    printf("Elapsed: %f seconds for binsearch method\n", (double)(soc - sic) / CLOCKS_PER_SEC);
    clock_t bic = clock();
    printf("Index of %d in array is: %d\n", b, classic_search_method(b, array, ARRAY_SIZE));
    clock_t boc = clock();
    printf("Elapsed: %f seconds for classic search method\n", (double)(boc - bic) / CLOCKS_PER_SEC);
    printf("==============================================================\n");
    clock_t ric = clock();
    printf("Index of %d in array is: %d\n", c, binsearch(c,array,ARRAY_SIZE));
    clock_t roc = clock();
    printf("Elapsed: %f seconds for binsearch method\n", (double)(roc - ric) / CLOCKS_PER_SEC);
    clock_t fic = clock();
    printf("Index of %d in array is: %d\n", c, classic_search_method(c, array, ARRAY_SIZE));
    clock_t foc = clock();
    printf("Elapsed: %f seconds for classic search method\n", (double)(foc - fic) / CLOCKS_PER_SEC);
    printf("==============================================================\n");

    return 0;
}