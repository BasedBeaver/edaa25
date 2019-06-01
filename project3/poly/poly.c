#include <stdio.h>
#include <stdlib.h>

#include "poly.h"

#define MAX_SIZE 100;

struct poly_t {
	int coef[MAX_SIZE];
	int exp[MAX_SIZE];
	int size;
};

poly_t*	new_poly_from_string(const char* c)
{

}

void free_poly(poly_t* p)
{
	free(p);
}

poly_t*	mul(poly_t* p1, poly_t* p2)
{

}

void print_poly(poly_t* p)
{

}
