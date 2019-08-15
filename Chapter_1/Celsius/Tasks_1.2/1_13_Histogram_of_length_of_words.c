#include <stdio.h>

int horizontalScale(int array[]) {
	int max, i;
	max = array[0];
	for (i = 0; i < 15; i++)
		if (max < array[i])
			max = array[i];
	return max;
}

int maxHorizontalValue(int array[]) {
	int max, i;
	max = array[0];
	for (i = 0; i < 15; i++)
		if (max < array[i])
			max = array[i];
	return max;
}

int main() {
	int c, i, j, nc;
	nc = 0;
	int array[15];
	for (int i = 0; i < 15; i++)
		array[i] = 0;
	while ((c = getchar()) != EOF){
		nc++;
		if (c == ' ' || c == '\n' || c == '\t'){
			if (nc > 15)
				printf("You entered too long word. Please try again\n");
			else
				array[nc - 1]++;
			nc = 0;		
		}
	}
	for (j = 0; j < 15; j++) {
		if (array[j] == 0)
			continue;
		if (j < 10)
			printf(" %d| ", j);		
		else
			printf("%d| ", j);			
		for (int k = 0; k < array[j]; k++)
			printf("%c ", '*');
		printf("\n");		
	}
	
	printf("%s", "   ");
	int a = horizontalScale(array);
	for (i = 1; i <= a; i++)
		printf("%s", "--");
	printf("%c", '>');
	printf("\n");
	printf("%s", "   ");
	int d = maxHorizontalValue(array);
	for (i = 1; i <= d; i++)
		printf(" %d", i);
	printf("\n");

	return 0;
}