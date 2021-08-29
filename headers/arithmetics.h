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
 * @brief Stores most recent error code.
 *
 * Heavily lightweight errno analog.
 */
extern int ERRTYPE;
/**
 * enum state - Enumeration of possible equation roots state.
 */
enum solutions_type {
	/**
         * If equation has infinite solutions.
         */
        INF_SOL = -1,
        /**
         * If equation has no solutions.
         */
        NO_SOL = 0,
        /**
         * If equation has one solution.
         */
        ONE_SOL = 1,
        /**
         * If equation has two solutions.
         */
        TWO_SOL = 2,
};
/**
 * Result of comparation of two values.
 */
enum compare_result {
	LESS  = -1,
	EQUAL = 0,
	MORE  = 1
};	
/**
 * @brief Generalized error types.
 *
 */
enum errors {
	/**
	 * No errors.
	 */
	NO_ERR = 0,
	/**
	 * NULL pointer error.
	 */
	ADDR_ERR = 1,
	/**
	 * Ifinum or NaN double value error.
	 */
	DOUBLE_ERR = 2,
	/**
	 * Two pointers points to same address.
	 */
	SAME_POINT_ERR = 3,
	/**
	 * Unknown error type
	 */
	UNKNOWN_ERR = 4
};

/**
 * struct solution - Stores solution of equation.
 */
struct equation_sol {
        /**
         * First root of equation and only one if its linear equation with one solution.
         */
        double x1;
        /**
         * Second root (if it is quadratic equation).
         */
        double x2;
        /**
         * State of equation.
         */
        enum solutions_type type;
};

/**
 * @brief coefficient structure.
 */ 
struct coefficients {
        double val[10];
	int coeff_n;
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
 * @param c Pointer to coefficient structure
 *
 * @return Discriminant of quadratic equation.
 */
double discr(const double a, const double b, const double c);

/**
 * @brief Solves linear equation.
 *
 * Solves linear equation and writes solutions into solution strucutre.
 * If linear equation has no solutions, sets sol state to NO_SOL.
 * If linear equation has infinity solutions, sets sol state to INF_SOL.
 * If linear equation has one solution, sets sol state to ONE_SOL,
 * calculate root and sets sol x1 value to root value.
 *
 * @param a Coefficient at x.
 * @param b Free coefficient
 * @param sol Pointer to solution structure.
 * 
 * @return If any errors returns error name, overwise returns 0
 */
int linear(const double b, const double c, struct equation_sol *sol);

/**
 * @brief Solve quadratic equation.
 *
 * Checks if quadratic equation has solutions, if it has, sets sol state to
 * TWO_SOL and calculate roots via quadratic_roots() function
 * overwise sets sol state to NO_SOL.
 *
 * @param c Pointer to coefficient structure.
 * @param sol Pointer to solution structure.
 *
 */
int quadratic(const struct coefficients *c, struct equation_sol *sol);

/**
 * calculates roots of quadratic equation.
 *
 * Calculate roots of quadratic equation (assuming discriminant >= 0)
 * and writes them into sol x1 and x2 values.
 *
 * @param c Pointer to coefficient structure.
 * @param discriminant Discriminant value.
 * @param sol Pointer to solutions structure.
 *
 */
int quadratic_roots(const struct coefficients *c, const double discriminant, struct equation_sol *sol);

/**
 * solves equation with coefficients a, b, c.
 *
 * Determines equation type (depends on a value) and calls
 * linear() or quadratic() function.
 *
 * @param a Coefficient at x^2.
 * @param b Coefficient at x.
 * @param c Free coefficient.
 * @param sol Pointer to solution structure
 */
int solve(const struct coefficients *coeff, struct equation_sol *sol);

/**
 * compares double with 0.
 *
 * Checks if val is in the vicinity of 0 with accuracy 10e-6.
 *
 * @param val Double value which shoild be compared with 0.
 *
 * @return 1 if number in the vicinity of 0, overwise return 1.
 */
int cmp_to_zero(const double val);

/**
 * Compares two double value.
 *
 * @param val1 First value.
 * @param val2 Second value.
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
