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
	int size = poly->size;

	for (i = 0; i < size; i++) {

		int coeff = poly->coeff[i];
		int coeff_plus_1 = poly->coeff[i + 1];
                int exp = poly->exp[i];

		if (coeff == 0) {
			continue;
		}
		if (coeff > 1) {
			if (exp == 0) {
				printf("%d", coeff);
			}
			else if (exp == 1) {
				printf("%dx", coeff);
			}
			else {
				printf("%dx^%d", coeff, exp);
			}
		}
		else if (coeff == 1 || coeff == (-1)) {
			if (exp == 0) {
				printf("%d", coeff);
			}
			else if (exp == 1) {
				printf("x");
			}
			else {
				printf("x^%d", exp);
			}
		}
		else if (coeff < 0) {
			if (exp == 0) {
				printf("%d", coeff * (-1));
			}
			else if (exp == 1) {
				printf("%dx", coeff * (-1));
			}
			else {
				printf("%dx^%d", coeff * (-1), exp);
			}
		}

		while (i + 1 < size && coeff_plus_1 == 0) {
			i++;
			coeff_plus_1 = poly->coeff[i + 1];
		}

		if (i + 1 < size && coeff_plus_1 != 0) {
			if (coeff_plus_1 > 0) {
				printf(" + ");
			}
			else {
				printf(" - ");
			}
		}
	}
	putchar('\n');
}
