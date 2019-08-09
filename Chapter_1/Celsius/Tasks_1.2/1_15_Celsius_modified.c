#include <stdio.h>

float fahr_to_celsium (float fahr);
void print_fahr_to_celsium_table ();

int main () {
	print_fahr_to_celsium_table();
	return 0;
}

void print_fahr_to_celsium_table (){
	float fahr, celsius;
	
	printf("Fahrengeit into Celsius table\n");
	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {	
		celsius = fahr_to_celsium(fahr);
		printf("%4.0F%6.1F\n", fahr, celsius);
	}
}

float fahr_to_celsium (float fahr) {
	float celsius;
	celsius = (5.0/9.0) * (fahr - 32.0);
	return celsius;
}