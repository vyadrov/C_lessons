#include <stdio.h>

int main () {
	int lower, upper, step;
	float fahr, celsius;
	lower = -30;
	upper = 300;
	step = 5;
	celsius = lower;
	printf("Celsius into Fahrengeit table\n");
	while (celsius <= upper) {
		fahr = celsius * 1.8 + 32.0;
		printf("%6.0F\t%3.0F\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}