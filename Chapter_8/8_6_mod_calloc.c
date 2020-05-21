#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 50
#define NUMBERS_PER_STRING 10

void *mod_calloc(size_t num, size_t size) {
	void *result = NULL;
	result = malloc(num * size);
	memset(result, 0, num * size);
}

int main(void) {

  	int *p = NULL;
  	int i = 0;
	
  	p = mod_calloc(SIZE, sizeof *p);
	
  	if (p == NULL) {  	
  	  printf("Memory cannot be allocated\n");
  	} else {  	
  	  for (i = 0; i < SIZE; i++) {
  	    printf("%d ", p[i]);
  	    if (i % NUMBERS_PER_STRING == (NUMBERS_PER_STRING - 1)) {
			printf("\n");
  	    }
  	  }
  	  printf("\n");
  	  free(p);
  	}
	
  	return 0;
}