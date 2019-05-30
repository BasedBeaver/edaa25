#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poly.h"
#include "error.h"

#define MAX_SIZE	(10000)

static void poly_test(const char* a, const char* b)
{
	poly_t*		p;
	poly_t*		q;
	poly_t*		r;

	printf("Begin polynomial test of (%s) * (%s)\n", a, b);

	p = new_poly_from_string(a);
	q = new_poly_from_string(b);

	print_poly(p);
	print_poly(q);
	r = mul(p, q);
	print_poly(r);

	free_poly(p);
	free_poly(q);
	free_poly(r);

	printf("End polynomial test of (%s) * (%s)\n", a, b);
}

static int read_poly(char* p, size_t n)
{
	int		c;
	size_t		i;
	char		stop[] = ",\n";

	i = 0;

	while ((c = getchar()) != EOF && strchr(stop, c) == NULL) {
		if (i == n)
			error("unexpected input size");

		p[i] = c;
		i += 1;
	}

	p[i] = 0;

	if (c != EOF)
		ungetc(c, stdin); 

	return i;
}

int main(int argc, char** argv)
{
	static char	p[MAX_SIZE];
	static char	q[MAX_SIZE];
	int		c;
	int		first = 1;	

	progname = argv[0];

	while (read_poly(p, sizeof p)) {

		/* print empty line between tests. */
		if (first)
			first = 0;
		else
			putchar('\n');

		c = getchar();
		if (c != ',')
			error("expected ,");

		read_poly(q, sizeof q);
		c = getchar();
		if (c != '\n')
			error("expected \\n");
		poly_test(p, q);
	}

	return 0;
}
