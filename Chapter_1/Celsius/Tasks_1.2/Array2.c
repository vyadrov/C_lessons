#include <stdio.h>

#define N 2
#define K 3


void sort_array(int array[][K]) {
	int i, j;
	for (i = 1; i < N*K; i++){
		int k = i;
		while (k > 0 && array[(k - 1)/K][(k-1)%K] > array[k/K][k%K]) {
			int tmp = array[(k - 1)/K][(k-1)%K];
			array[(k - 1)/K][(k-1)%K] = array[k/K][k%K];
			array[k/K][k%K] = tmp;
			k = k - 1;		
		}
	}
}

int main(int argc, char* argv[]) {
int i, j, array[N][K];
printf ("Enter any values:\n");
for(i = 0; i < N; i++)
	for (j = 0; j < K; j++)
		scanf ("%d", &array[i][j]);
	printf("Your array is: \n");
	
for (i = 0; i < N; i++) {
	for (j = 0; j < K; j++)
		printf("%d  ", array[i][j]);
		printf ("\n");		
	}
	printf("Your sorted array is: \n");
	sort_array(array);
	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++)
			printf("%d  ", array[i][j]);
			printf ("\n");
		}
return 0;
}