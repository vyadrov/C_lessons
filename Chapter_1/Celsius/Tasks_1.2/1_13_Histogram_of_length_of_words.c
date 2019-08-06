#include <stdio.h>

int main() {
	int c, i, j, nc;
	nc = 0;
	int array[15];
	for (int i = 0; i < 15; i++)
		array[i] = 0;
	while ((c = getchar()) != EOF){
		nc++;
		if (c == ' ' || c == '\n' || c == '\t'){
			array[nc - 1]++;
			nc = 0;
		}
	}

	for (j = 0; j <= 15; j++) {
		if (j <10)
		printf(" %d: %d\n", j, array[j]);
		else
			printf("%d: %d\n", j, array[j]);
	}

	return 0;
}