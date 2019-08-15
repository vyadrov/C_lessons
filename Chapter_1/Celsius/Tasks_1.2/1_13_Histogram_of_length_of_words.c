#include <stdio.h>
#define N 15

void wordScan(int array[N]) {
	int c, i, nc;
	nc = 0;
	for (int i = 0; i < N; i++)
		array[i] = 0;
	while ((c = getchar()) != EOF){
		nc++;
		if (c == ' ' || c == '\n' || c == '\t'){
			if (nc > N)
				printf("You entered too long word. Please try again\n");
			else
				array[nc - 1]++;
			nc = 0;		
		}
	}
}

void printHistogram(int array[N]) {
	int j, i, max;
	for (i = 0; i < N; i++) {
		if (array[i] == 0)
			continue;
		if (i < 10)
			printf(" %d| ", i);		
		else
			printf("%d| ", i);
		for (j = 0; j < array[i]; j++)
			printf("%s ", " *");
		printf("\n");		
	}
	max = array[0];
	for (i = 0; i < N; i++)
		if (max < array[i])
			max = array[i];
		for (i = 0; i <= max; i++)
		printf("%s", "---");
	printf("%c\n", '>');
	printf("%s", "   ");
	for (i = 0; i < N; i++)
		if (max < array[i])
			max = array[i];
		for (i = 1; i <= max; i++)
			if (i < 10)
				printf("  %d", i);
			else
				printf(" %d", i);
	printf("\n");	
}

int main() {
	int array[N];
	int a, j, i;
	wordScan(array);
	printHistogram(array);
	
	return 0;
}