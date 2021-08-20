#include "solve.h"

void linear(double a, double b, double c, struct solution *s)
{
	if (fabs(b) < ACCURACY) {
		if (fabs(c) < ACCURACY)
			s->type = INF_SOL;
		else
			s->type = NO_SOL;
	} else {
		s->type = ONE_SOL;
		s->x1 = c / b;
	}
}

void quadratic_roots(double a, double b, double d, struct solution *s) 
{
	s->x1 = (-b - sqrt(d)) / (2 * a);
        s->x2 = (-b + sqrt(d)) / (2 * a);
}
void quadratic(double a, double b, double c, struct solution *s) 
{
	double d = discr(a, b, c);
	if (d < 0) {
		s->type = NO_SOL;
	} else {
		s->type = TWO_SOL;
		quadratic_roots(a, b, d, s);
	}
}

void solve(double a, double b, double c, struct solution *s)
{
	(fabs(a) < ACCURACY) ? linear(a, b, c, s) : quadratic(a, b, c, s); 
}

void print_roots(struct solution *s)
{
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
	char i[MAXLEN];
       	char *ptr;
	scanf("%s", i);
	errno = 0;
	*c = strtod(i, &ptr);
	if (errno != 0 || *ptr != '\0') {
		fprintf(stderr,"value could not be represented as a double exactly\n");
		return 0;
	}
	return 1;
}
