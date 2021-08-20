#ifndef SOLVE_H
#define SOLVE_H

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/* calculate discriminant */
#define discr(a, b, c) (b * b - 4 * a * c)

/* accuracy */
#define ACCURACY 10e-10

/* maximum input lenghtj */
#define MAXLEN 100

/* solution state */
enum state {
	NO_SOL,
	ONE_SOL,
	TWO_SOL,
	INF_SOL
};

/* store solutions */
struct solution {
        double x1;
        double x2;
        enum state type;
};

/* solve linear equation */
void linear(double a, double b, double c, struct solution *);

/* solve quadratic equation */
void quadratic(double a, double b, double c, struct solution *);

/* calculate roots of quadratic equasion with discr >= 0 */
void quadratic_roots(double a, double b, double discriminant, struct solution *);

/* define equation type */
void solve(double a, double b, double c, struct solution *s);

/* print solutions(or no solutions) */
void print_roots(struct solution *);

/*
 * reads from arguments to coefficients and returns 0  
 * overwies returns -1
 */
int read_coefficient(double *coeff);

#endif //SOLVE_H
