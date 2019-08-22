#include <stdio.h>
#include <math.h>

#define N 8

void determineRanges(int x) {
	char  min_signed_char, max_signed_char;
	short min_signed_short, max_signed_short;
	int min_signed_int, max_signed_int;
	long min_signed_long, max_signed_long;
	unsigned char max_unsigned_char;
	unsigned short max_unsigned_short;
	long int min_signed_long_int, max_signed_long_int;
	unsigned int max_unsigned_int;
	unsigned long max_unsigned_long;
	
	min_signed_char = -(pow(2, (sizeof(char)*N - 1)));
	max_signed_char = pow(2, (sizeof(char)*N - 1)) - 1;
	min_signed_short = -(pow(2, (sizeof(short)*N - 1)));
	max_signed_short = pow(2, (sizeof(short)*N - 1)) - 1;
	min_signed_int = -(pow(2, (sizeof(int)*N - 1)));
	max_signed_int = pow(2, (sizeof(int)*N - 1)) - 1;
	min_signed_long = -(pow(2, (sizeof(long)*N - 1)));
	max_signed_long = pow(2, (sizeof(long)*N - 1)) - 1;
	min_signed_long_int = -(pow(2, (sizeof(long int)*N - 1)));
	max_signed_long_int = pow(2, (sizeof(long int)*N - 1)) - 1;
	max_unsigned_char = pow(2, sizeof(unsigned char)*N) - 1;
	max_unsigned_short = pow(2, sizeof(unsigned short)*N) - 1;
	max_unsigned_int = pow(2, sizeof(unsigned int)*N) - 1;
	max_unsigned_long = pow(2, sizeof(unsigned long)*N) - 1;
	printf("Minimum Signed Char %hhd\n", min_signed_char);
	printf("Maximum Signed Char % hhd\n", max_signed_char);
	printf("Minimum Signed Short %hd\n", min_signed_short);
	printf("Maximum Signed Short % hd\n", max_signed_short);
	printf("Minimum Signed Int %d\n", min_signed_int);
	printf("Maximum Signed Int % d\n", max_signed_int);
	printf("Minimum Signed Long %ld\n", min_signed_long);
	printf("Maximum Signed Long % ld\n", max_signed_long);
	printf("Minimum Signed Long Int %ld\n", min_signed_long_int);
	printf("Maximum Signed Long Int % ld\n\n", max_signed_long_int);
	printf("Maximum Unsigned Char %hhu\n", max_unsigned_char);
	printf("Maximum Unsigned Short %hu\n", max_unsigned_short);
	printf("Maximum Unsigned Int %u\n", max_unsigned_int);
	printf("Maximum Unsigned Long %lu\n", max_unsigned_long);
}


int main () {
	int a;
	determineRanges(a);
	return 0;
}