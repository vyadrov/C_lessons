#include <stdio.h>
#define N 20

void wordscan(int array[N]) {
	int c, i;
	for (i = 0; i < N; i++)
		//array[i] = 0;
	while ((c = getchar()) != '\n') {
		if (c != EOF)
			putchar(c);
	}
}

int main () {
	int array[N];
	wordscan(array);

	return 0;
}