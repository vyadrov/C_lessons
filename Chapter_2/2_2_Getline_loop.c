#include <stdio.h>
#define N 20

void mygetline(int array[N]) {
	int c, i;
	for (i = 0; i < N; i++)
		array[i] = 0;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (i >= N - 1) {
			printf("You entered too long word.\n");
			break;
		}
		if (c != '\n') {
			array[i] = c;
			i++;
		}
		else
			break;
	}
}

int main () {
	int array[N];
	mygetline(array);
	for (int i = 0; array[i] != 0; i++)
		putchar(array[i]);
	putchar('\n');
	return 0;
}