#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "error.h"
#include "poly.h"


#define MAX_SIZE 10

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

int nbr_from_string(const char* poly_str, int* i)
{
	int nbr = 0;
	while (isdigit(poly_str[*i])) {
		nbr = nbr*10 + (poly_str[*i] - '0');
		(*i)++;
	}
	return nbr;
}

poly_t*	new_poly_from_string(const char* poly_str)
{
	struct poly_t* poly = new_poly();

	int i;
	int curr_coeff = 1;
	int end_coeff = 0;
	int sign = 1;
	int size_c = 0;

	for (i = 0; i < strlen(poly_str); i++) {
		if (i > 0 && (poly_str[i-1] == 'x' && poly_str[i] == ' ')) {
			poly->coeff[size_c] =  curr_coeff * sign;
			poly->exp[size_c] = 1;
			sign = 1;
			curr_coeff = 1;
			size_c++;

		}
		else if (poly_str[i] == '^') {
			i++;
			int exp = nbr_from_string(poly_str, &i);
			poly->coeff[size_c] =  curr_coeff * sign;
			poly->exp[size_c++] = exp;
			sign = 1;
			curr_coeff = 1;
		}
		else if (poly_str[i] == '-') {
			sign = -1;
		}
		else if (isdigit(poly_str[i])) {
			curr_coeff = nbr_from_string(poly_str, &i);
			if (poly_str[i] != 'x') {
				end_coeff = 1;
			}
		}
	}
	if (end_coeff) {
		poly->coeff[size_c] = curr_coeff;
		poly->exp[size_c++] = 0;
	}
	poly->size = size_c;

	return poly;
}

void free_poly(poly_t* p)
{
	free(p);
}

poly_t*	mul(poly_t* p1, poly_t* p2)
{
	struct poly_t* r = new_poly();
	int size_c = 0;
	for (int i = 0; i < p1->size; i++) {
		for (int j = 0; j < p2->size; j++) {
			r->exp[size_c] = p1->exp[i] + p2->exp[j];
			r->coeff[size_c] = p1->coeff[i] * p2->coeff[j];
			size_c++;
		}
	}

	r->size = size_c;

	for (int i = 0; i < r->size - 1; i++) {
		for (int j = i + 1; j < r->size; j++) {
			if (r->exp[i] == r->exp[j]) {
				r->coeff[i] += r->coeff[j];
				r->coeff[j] = 0;
			}
		}
	}

	return r;
}

void print_poly(poly_t* poly)
{
	int i;
	for (i = 0; i < poly->size; i++) {
		if (poly->coeff[i] == 0)
			continue;
		if (poly->coeff[i] > 1) {
			if (poly->exp[i] == 0)
				printf("%d", poly->coeff[i]);
			else if (poly->exp[i] == 1)
				printf("%dx", poly->coeff[i]);
			else
				printf("%dx^%d", poly->coeff[i], poly->exp[i]);
		}
		else if (poly->coeff[i] == 1 || poly->coeff[i] == -1 ) {
			if (poly->exp[i] == 0)
				printf("%d", poly->coeff[i]);
			else if (poly->exp[i] == 1)
				printf("x");
			else
				printf("x^%d", poly->exp[i]);
		}
		else if (poly->coeff[i] < 0) {
			if (poly->exp[i] == 0)
				printf("%d", poly->coeff[i] * - 1);
			else if (poly->exp[i] == 1)
				printf("%dx", poly->coeff[i] * -1);
			else
				printf("%dx^%d", poly->coeff[i] * -1, poly->exp[i]);

		}
		while (i + 1 < poly->size && poly->coeff[i+1] == 0)
			i++;
		if (i + 1 < poly->size && poly->coeff[i+1] != 0) {
			if (poly->coeff[i+1] > 0)
				printf(" + ");
			else
				printf(" - ");
		}
	}
	putchar('\n');

}
