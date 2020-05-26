#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define NALLOC 1024
#define SIZE 80
#define NUMBERS_PER_STRING 10

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

static Header *morecore(unsigned nu);
static void bfree(void *p, unsigned n);
void *mod_calloc(size_t , size_t );

int main(void) {

    int *a = NULL;
    char *b;
  	int i = 0;
	
  	a = mod_calloc(SIZE, sizeof *a);

  	if (a == NULL) { 
  		printf("Memory cannot be allocated\n");
  	} else {
  		for (i = 0; i < SIZE; i++) {
  			printf("%d ", a[i]);
  			if (i % NUMBERS_PER_STRING == (NUMBERS_PER_STRING - 1)) {
				printf("\n");
  			}
  		}
  		printf("\n");
  		bfree(a, sizeof *a);
  	}

  	b = mod_calloc(SIZE, sizeof *b);    
    printf("Successful\n");
    free(b);
  	return 0;
}

void *mod_calloc(size_t num, size_t size) {
	void *result = NULL;
	result = malloc(num * size);
	memset(result, 0, num * size);
}

static void bfree(void *p, unsigned n) {

	Header *bp;
    if (n < sizeof(Header))
    	return;
	
	bp = (Header *)p;
	bp->s.size = n / sizeof(Header);
	free(bp + 1);
}