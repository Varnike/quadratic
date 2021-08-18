#include "solve.h"

static struct solution linear(double a, double b, double c)
{
	struct solution s;
	if (!b) {
		if (!c)
			s.type = INF_SOL;
		else
			s.type = NO_SOL;
	} else {
		s.type = LINEAR;
		s.x1 = c / b;
	}
	return s;
}

static struct solution quadratic(double a, double b, double c) 
{
	struct solution s;
	double d = b * b - 4 * a * c;
	if (d < 0) {
		s.type = NO_SOL;
	} else {
		s.type = QUADR;
		s.x1 = (-b - sqrt(d)) / (2 * a);
		s.x2 = (-b + sqrt(d)) / (2 * a);
	}
	return s;
}

struct solution solve(double a, double b, double c)
{
	return (a == 0) ? linear(a, b, c) : quadratic(a, b, c);
}

void print(struct solution *s)
{
	switch (s->type) {
	case INF_SOL:
		printf("Infinite solutions\n");
		break;
	case NO_SOL:
		printf("No solutions\n");
		break;
	case LINEAR:
		printf("Solution: %f\n", s->x1);
		break;
	case QUADR:
		printf("Solutions: %f, %f\n", s->x1, s-> x2);
		break;
	}
}
