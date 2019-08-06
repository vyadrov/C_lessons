#include <stdio.h>

int main() {
	int c, tab, space, newString;
	tab = space = newString = 0;	
	printf("Please enter any text:\n");

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			++tab;
		else if (c == ' ')
			++space;
		else if (c == '\n')
			++newString;		
	}
	printf("You entered:\n tab = %d\n space = %d\n newString = %d\n", tab, space, newString);
	return 0;
}