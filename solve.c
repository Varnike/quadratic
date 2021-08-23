#include "solve.h"

const int MAXLEN = 100;
const double ACCURACY = 10e-6;

void linear(struct coefficients *coeff, struct solution *s)
{
	assert(s);
	if (cmp_to_zero(coeff->b)) {
		if (cmp_to_zero(coeff->c))
			s->type = INF_SOL;
		else
			s->type = NO_SOL;
	} else {
		s->type = ONE_SOL;
		s->x1 = coeff->c / coeff->b;
	}
}

void quadratic_roots(struct coefficients *coeff, double d, struct solution *s) 
{
	assert(s);
	s->x1 = (-coeff->b - sqrt(d)) / (2 * coeff->a);
        s->x2 = (-coeff->b + sqrt(d)) / (2 * coeff->a);
}
void quadratic(struct coefficients *coeff, struct solution *s) 
{
	assert(s);
	double d = discr(coeff);
	if (d < -ACCURACY) {
		s->type = NO_SOL;
	} else {
		s->type = TWO_SOL;
		quadratic_roots(coeff, d, s);
	}
}

void solve(double a, double b, double c, struct solution *s)
{
	assert(s);
	struct coefficients coeff;
	coeff.a = a;
	coeff.b = b;
	coeff.c = c;
	cmp_to_zero(a) ? linear(&coeff, s) : quadratic(&coeff, s); 
}

double discr(struct coefficients *coeff) 
{
	return (coeff->b * coeff->b - 4 * coeff->a * coeff->c);
}
void print_roots(struct solution *s)
{
	assert(s);
	switch (s->type) {
	case INF_SOL:
		printf("Infinite solutions\n");
		break;
	case NO_SOL:
		printf("No solutions\n");
		break;
	case ONE_SOL:
		printf("Solution: %f\n", s->x1);
		break;
	case TWO_SOL:
		printf("Solutions: %f, %f\n", s->x1, s-> x2);
		break;
	default:
		fprintf(stderr,"invalid state\n");
		break;
	}
}

int read_coefficient(double *c)
{
	assert(c);
	char input[MAXLEN];
       	char *ptr = NULL;
	scanf("%s", input);
	errno = 0;
	*c = strtod(input, &ptr);
	if (errno != 0 || *ptr != '\0') {
		fprintf(stderr,"value could not be represented as a double exactly\n");
		return 0;
	}
	return 1;
}

int cmp_to_zero(double val)
{
	return (fabs(val) < ACCURACY);
}
