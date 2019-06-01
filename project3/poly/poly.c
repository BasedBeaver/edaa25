#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poly.h"

#define MAX_SIZE 100

struct poly_t {
	int coeff[MAX_SIZE];
	int exp[MAX_SIZE];
	int size;
};

struct poly_t* new_poly()
{
	struct poly_t* p = malloc(sizeof(struct poly_t));
	memset(p->coeff, 0, MAX_SIZE * sizeof(int));
	memset(p->exp, 0, MAX_SIZE * sizeof(int));
	p->size = 0;
	return p;
}

poly_t*	new_poly_from_string(const char* c)
{
	struct poly_t* poly = new_poly();
	printf("TRYING TO PRINT SOME%s\n", c);

	for (i = 0; i < strlen(str); i++) {



	}


	return poly;
}

void free_poly(poly_t* p)
{
	free(p);
}

poly_t*	mul(poly_t* p1, poly_t* p2)
{
	return NULL;
}

void print_poly(poly_t* p)
{
	printf("printpoly\n");
}
