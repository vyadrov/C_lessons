#include <stdio.h>
#define N 5

int min(int array[]) {
	int min, i;
	min = array[0];
	for (i = 0; i < N; i++)
		if (min > array[i])
			min = array[i];	
	return min;
}

int max(int array[]) {
	int max, i;
	max = array[0];
	for (i = 0; i < N; i++)
		if (max < array[i])
			max = array[i];
	return max;
}

int sum(int array[]) {
	int sum, i;
	sum = 0;
	for (i = 0; i < N; i++)
		sum = sum + array[i];
	return sum;
}

void sort_array(int array[]) {
	int i;
	for (i = 1; i < N; i++) {
		int k = i;
		while (k > 0 && array[k - 1] > array[k]) {
			int tmp = array[k - 1];
			array[k - 1] = array[k];
			array[k] = tmp;
			k = k - 1;
		}
	}
}

int main(int argc, char* argv[]) {
	int i;
	int array[N];
	printf ("Enter any values:\n");
	for (i = 0; i < N; i++)
		scanf ("%d", &array[i]);
	printf("Your array is:");
	for (i = 0; i < N; i++)
		printf(" %d", array[i]);
	printf("\n");
	printf("Your sorted array is:");
	sort_array(array);
	for (i = 0; i < N; i++)
		printf(" %d", array[i]);
	printf("\n");
	printf("Min element of array: %d\n", min(array));
	printf("Max element of array: %d\n", max(array));
	printf("Sum of array's elements: %d\n", sum(array));
	return 0;
}