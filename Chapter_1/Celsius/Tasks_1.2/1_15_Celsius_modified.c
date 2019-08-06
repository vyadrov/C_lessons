#include <stdio.h>

void fahr_to_celsium();

void fahr_to_celsium (){
	float fahr, celsius;
	
	printf("Fahrengeit into Celsius table\n");
	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
	
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%4.0F%6.1F\n", fahr, celsius);
	}
}

int main () {
	fahr_to_celsium();
	return 0;
}