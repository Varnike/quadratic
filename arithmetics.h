/**
 * @file
 *
 * @brief Set of functions which can be used to solve linear or quadratic equation.
 *
 * @author Varnike
 *
 * @date 27 Aug, 17:09 UTC+5.
 */


#ifndef ARITHMETICS_H
#define ARITHMETICS_H

#include <cstring>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>

/**
 * stores most recent error code
 *
 * heavily lightweight errno analog
 */
extern int errtype;
/**
 * enum state - enumeration of possible equation roots state.
 */
enum solutions_type {
	/**
         * if equation has infinite solutions.
         */
        INF_SOL = -1,
        /**
         * if equation has no solutions.
         */
        NO_SOL = 0,
        /**
         * if equation has one solution.
         */
        ONE_SOL = 1,
        /**
         * if equation has two solutions.
         */
        TWO_SOL = 2,
};
/**
 * result of comparation of two values.
 */
enum compare_result {
	LESS  = -1,
	EQUAL = 0,
	MORE  = 1
};	
/**
 * @brief generalized error types.
 *
 */
enum errors {
	/**
	 * no errors.
	 */
	NO_ERR = 0,
	/**
	 * NULL pointer error.
	 */
	ADDR_ERR = 1,
	/**
	 * ifinum or NaN double value error.
	 */
	DOUBLE_ERR = 2,
	/**
	 * two pointers points to same address.
	 */
	SAME_POINT_ERR = 3,
	/**
	 * unknown error type
	 */
	UNKNOWN_ERR = 4
};

/**
 * struct solution - stores solution of equation.
 */
struct solution {
        /**
         * first root of equation and only one if its linear equation with one solution.
         */
        double x1;
        /**
         * second root (if it is quadratic equation).
         */
        double x2;
        /**
         * state of equation.
         */
        enum solutions_type type;
};

/**
 * @brief coefficient structure
 */ 
struct coefficients {
        double a;
        double b;
        double c;
};

/**
 * %ACCURACY: accuracy of double value.
 */
const double ACCURACY = 10e-6;

/**
 * @brief discriminant of quadratic equation.
 *
 * Calculates discrminant of quadratic equation with coefficients saved in coefficients structure.
 * 
 * @param c pointer to coefficient structure
 *
 * @return discriminant of quadratic equation.
 */
double discr(const double a, const double b, const double c);

/**
 * @brief solves linear equation.
 *
 * Solves linear equation and writes solutions into solution strucutre.
 * If linear equation has no solutions, sets sol state to NO_SOL.
 * If linear equation has infinity solutions, sets sol state to INF_SOL.
 * If linear equation has one solution, sets sol state to ONE_SOL,
 * calculate root and sets sol x1 value to root value.
 *
 * @param a coefficient at x.
 * @param b free coefficient
 * @param sol pointer to solution structure.
 * 
 * @return if any errors returns error name, overwise returns 0
 */
int linear(const double b, const double c, struct solution *sol);

/**
 * @brief solve quadratic equation.
 *
 * Checks if quadratic equation has solutions, if it has, sets sol state to
 * TWO_SOL and calculate roots via quadratic_roots() function
 * overwise sets sol state to NO_SOL.
 *
 * @param c pointer to coefficient structure.
 * @param sol pointer to solution structure.
 *
 */
int quadratic(const struct coefficients *c, struct solution *sol);

/**
 * calculates roots of quadratic equation.
 *
 * Calculate roots of quadratic equation (assuming discriminant >= 0)
 * and writes them into sol x1 and x2 values.
 *
 * @param c pointer to coefficient structure.
 * @param discriminant discriminant value.
 * @param sol pointer to solutions structure.
 *
 */
int quadratic_roots(const struct coefficients *c, const double discriminant, struct solution *sol);

/**
 * solves equation with coefficients a, b, c.
 *
 * Determines equation type (depends on a value) and calls
 * linear() or quadratic() function.
 *
 * @param a coefficient at x^2.
 * @param b coefficient at x.
 * @param c free coefficient.
 * @param sol pointer to solution structure
 */
int solve(const struct coefficients *coeff, struct solution *sol);

/**
 * compares double with 0.
 *
 * Checks if val is in the vicinity of 0 with accuracy 10e-6.
 *
 * @param double value which shoild be compared with 0.
 *
 * @return returns 1 if number in the vicinity of 0, overwise return 1.
 */
int cmp_to_zero(const double val);

/**
 * compares two double value.
 *
 * @param val1 first value.
 * @param val2 second value.
 *
 * @return EQUAL, LESS or MORE depending on val1 and val2 values.
 */
int cmp_double(double val1, double val2);

/**
 * Returns a pointer to the textual description of the code errtype.
 *
 * Uses error enumeration to determine error string.
 * @param errt error code.
 *
 * @return Pointer to a null-terminated byte string corresponding to the errtype code.
 */
const char *errmsg(int errt);

#endif //ARITHMETICS_H
