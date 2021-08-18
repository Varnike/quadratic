#ifndef SOLVE_H
#define SOLVE_H
#include <stdio.h>
#include <math.h>

/* solution state */
enum state {
	LINEAR,
	NO_SOL,
	QUADR,
	INF_SOL
};
struct solution {
        double x1;
        double x2;
        enum state type;
};

/* solve linear equation */
static struct solution linear(double , double , double );

/* solve quadratic equation */
static struct solution quadratic(double , double , double );

/* define equation type */
struct solution solve(double , double , double );

/* print solutions(or no solutions) */
void print(struct solution *);
#endif //SOLVE_H
