#include <stdio.h>
#include <math.h>

void determineRanges(int x) {
	char  a, b;
	short c, d;
	int e, f;
	long g, h;
	unsigned char m;
	unsigned short n;
	long int k, l;
	unsigned int o;
	unsigned long p;
	
	a = -(pow(2, (sizeof(char)*8 - 1)));
	b = pow(2, (sizeof(char)*8 - 1)) - 1;
	c = -(pow(2, (sizeof(short)*8 - 1)));
	d = pow(2, (sizeof(short)*8 - 1)) - 1;
	e = -(pow(2, (sizeof(int)*8 - 1)));
	f = pow(2, (sizeof(int)*8 - 1)) - 1;
	g = -(pow(2, (sizeof(long)*8 - 1)));
	h = pow(2, (sizeof(long)*8 - 1)) - 1;
	k = -(pow(2, (sizeof(long int)*8 - 1)));
	l = pow(2, (sizeof(long int)*8 - 1)) - 1;
	m = pow(2, sizeof(unsigned char)*8) - 1;
	n = pow(2, sizeof(unsigned short)*8) - 1;
	o = pow(2, sizeof(unsigned int)*8) - 1;
	p = pow(2, sizeof(unsigned long)*8) - 1;
	printf("Minimum Signed Char %hhd\n", a);
	printf("Maximum Signed Char % hhd\n", b);
	printf("Minimum Signed Short %hd\n", c);
	printf("Maximum Signed Short % hd\n", d);
	printf("Minimum Signed Int %d\n", e);
	printf("Maximum Signed Int % d\n", f);
	printf("Minimum Signed Long %ld\n", g);
	printf("Maximum Signed Long % ld\n", h);
	printf("Minimum Signed Long Int %ld\n", k);
	printf("Maximum Signed Long Int % ld\n\n", l);
	printf("Maximum Unsigned Char %hhu\n", m);
	printf("Maximum Unsigned Short %hu\n", n);
	printf("Maximum Unsigned Int %u\n", o);
	printf("Maximum Unsigned Long %lu\n", p);
}


int main () {
	int a;
	determineRanges(a);
	return 0;
}