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
			if (nc > 15) {
				printf("You entered too long word. Please try again\n");
				nc = 0;
				continue;
			}	
			array[nc - 1]++;
			nc = 0;		
		}
	}
	for (j = 0; j <= 15; j++) {
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
	
	printf("%s", "---------------------------------------");
	printf("%c", '>');
	printf("\n");
	printf("%s", "   ");
	for (j = 1; j <= 15; j++)
		printf(" %d", j);

	return 0;
}