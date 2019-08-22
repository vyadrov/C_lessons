#include <stdio.h>
#include <math.h>

#define A 8
#define B 16
#define C 32
#define D 64

void determineRanges(int x) {
	int a, b, c, d, e, f, g, h, m, n;
	long int k, l, o, p;
	
	a = -(pow(2, (A - 1)));
	b = pow(2, (A - 1)) - 1;
	c = -(pow(2, (B - 1)));
	d = pow(2, (B - 1)) - 1;
	e = -(pow(2, (C - 1)));
	f = pow(2, (C - 1)) - 1;
	g = -(pow(2, (C - 1)));
	h = pow(2, (C - 1)) - 1;
	k = -(pow(2, (D - 1)));
	l = pow(2, (D - 1)) - 1;
	m = pow(2, A) - 1;
	n = pow(2, B) - 1;
	o = pow(2, C) - 1;
	p = pow(2, C) - 1;
	printf("Minimum Signed Char %d\n", a);
	printf("Maximum Signed Char % d\n", b);
	printf("Minimum Signed Short %d\n", c);
	printf("Maximum Signed Short % d\n", d);
	printf("Minimum Signed Int %d\n", e);
	printf("Maximum Signed Int % d\n", f);
	printf("Minimum Signed Long %d\n", g);
	printf("Maximum Signed Long % d\n", h);
	printf("Minimum Signed Long Int %ld\n", k);
	printf("Maximum Signed Long Int % ld\n\n", l);
	printf("Maximum Unsigned Char %d\n", m);
	printf("Maximum Unsigned Short %d\n", n);
	printf("Maximum Unsigned Int %ld\n", o);
	printf("Maximum Unsigned Long %ld\n", p);
}


int main () {
	int a;
	determineRanges(a);
	return 0;
}