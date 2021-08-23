/**
 * @file
 *
 * @brief Set of functions which can be used to solve linear or quadratic equasion.
 * To read coefficients use read_coefficient() function, to solve equasion
 * use solve() function and to print roots use print_roots() function.
 *
 * @author Varnike
 */

#ifndef SOLVE_H
#define SOLVE_H

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>

/**
 * enum state - enumeration of possible equation roots state.
 */
enum state {
	/**
	 * if equation has no solutions.
	 */ 
	NO_SOL = 1,
	/**
	 * if equation has one solution.
	 */
	ONE_SOL = 2,
	/**
	 * if equation has two solutions.
	 */
	TWO_SOL = 3,
	/**
	 * if equation has infinite solutions.
	 */
	INF_SOL = 4
};

/**
 * struct solution - stores solution of equation.
 */
struct solution {
	/**
	 * first root of equasion and only one if its linear equasion with one solution.
	 */
        double x1;
	/**
	 * second root (if it is quadratic equasion).
	 */
        double x2;
	/**
	 * state of equasion.
	 */
        enum state type;
};

struct coefficients {
	double a;
	double b;
	double c;
};

/**
 * %ACCURACY: accuracy of double value.
 */ 
extern const double ACCURACY;
/**
 * %MAXLEN: maximum input length.
 */
extern const int MAXLEN;

/**
 * @brief discriminant of quadratic equasion.
 *
 * Calculates discrminant of quadratic equasion with coefficients saved in coefficients structure.
 *
 * @param c pointer to coefficient structure
 *
 * @return discriminant of quadratic equasion.
 */
double discr(struct coefficients *c);

/**
 * @brief solves linear equation.
 *
 * Solves linear equasion and writes solutions into solution strucutre.
 * If linear equasion has no solutions, sets sol state to NO_SOL.
 * If linear equasion has infinity solutions, sets sol state to INF_SOL.
 * If linear equasion has one solution, sets sol state to ONE_SOL,
 * calculate root and sets sol x1 value to root value.
 *
 * @param c pointer to coefficients structure.
 * @param sol pointer to solution structure.
 *
 */ 
void linear(struct coefficients *c, struct solution *sol);

/**
 * @brief solve quadratic equasion.
 *
 * Checks if quadratic equasion has solutions, if it has, sets sol state to
 * TWO_SOL and calculate roots via quadratic_roots() function
 * overwise sets sol state to NO_SOL.
 *
 * @param c pointer to coefficient structure.
 * @param sol pointer to solution structure.
 *
 */
void quadratic(struct coefficients *c, struct solution *sol);

/**
 * calculates roots of quadratic equation.
 *
 * Calculate roots of quadratic equasion (assuming discriminant >= 0)
 * and writes them into sol x1 and x2 values.
 *
 * @param c pointer to coefficient structure.
 * @param discriminant discriminant value.
 * @param sol pointer to solutions structure.
 *
 */
void quadratic_roots(struct coefficients *c, double discriminant, struct solution *sol);

/**
 * solves equasion with coefficients a, b, c.
 *
 * Determines equasion type (depends on a value) and calls
 * linear() or quadratic() function.
 *
 * @param a coefficient at x^2.
 * @param b coefficient at x.
 * @param c free coefficient.
 * @param sol pointer to solution structure
 */ 
void solve(double a, double b, double c, struct solution *sol);

/** 
 * prints equasion roots.
 *
 * Prints equasion roots depending on sol state.
 *
 * @param sol pointer to solution structure.
 */
void print_roots(struct solution *sol);

/**
 * reads coefficients from stdin.
 *
 * Checks input. If input value can be represented as double exactly,
 * reads it to coeff and returns 1. Overwise prints error mesage and
 * returns 0.
 *
 * @param coeff pointer to coefficient.
 *
 * @return 1 if input data is valid, overwise reurns 0 
 */
int read_coefficient(double *coeff);

/**
 * compares double with 0.
 *
 * Checks if val is in the vicinity of 0 with accuracy = ACCURACY.
 *
 * @param double value which shoild be compared with 0.
 *
 * @return returns 1 if number in the vicinity of 0, overwise return 1.
 */ 
int cmp_to_zero(double val);

#endif //SOLVE_H
