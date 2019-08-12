#include <stdio.h>

#define N 4
#define K 3

int array[N][K] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{10, 11, 12}
};
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

int bigger_row_sum(int array[][K]) {
	int sum_1 = 0, bigger_sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++)
			sum_1 = sum_1 + array[i][j];
		if (bigger_sum < sum_1)
			bigger_sum = sum_1;
		sum_1 = 0;		
	}
	return bigger_sum;
}

int min_column_sum(int array[][K]) {
	int sum_1 = 0;
	int min_sum;
	for (int i = 0; i < K; i++){
		for (int j = 0; j < N; j++)
			sum_1 = sum_1 + array[j][i];
		if (i == 0)
			min_sum = sum_1;
		if (min_sum > sum_1)
			min_sum = sum_1;
		sum_1 = 0;		
	}
	return min_sum;
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
		printf("Max sum of array's rows: %d\n", bigger_row_sum(array));
		printf("Min sum of array's column: %d\n", min_column_sum(array));
		printf("Your sorted array is: \n");
		sort_array(array);
		for (i = 0; i < N; i++) {
			for (j = 0; j < K; j++)
				printf("%d  ", array[i][j]);
				printf ("\n");
			}
	return 0;
}