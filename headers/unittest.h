/**
 * @file
 * Set of functions for testing the program.
 * @author Varnike
 * @date 28 Aug 16:17 UTC+5
 */

#ifndef UNITTEST_H
#define UNITTEST_H

#include "arithmetics.h"

enum colors {
	DEFAULT = 0,
	RED     = 1,
	GRN     = 2,
	BLU     = 3
};

const int TESTNUMB = 10;

/**
 * Coefficients array for tests.
 */
const struct coefficients test_coeffs[TESTNUMB] = {
	{{0, 0, 0}, 3},
	{{0, 0, 1}, 3},
	{{0, 1, 1}, 3},
	{{99, 9832, -3092.32}, 3},
	{{9, 45, 0}, 3},
	{{0, 0, -9}, 3},
	{{7, 7, 7}, 3},
	{{101, 4, 88}, 3},
	{{-34, -43, 323}, 3},
	{{23.4, -88.23, -989.12}, 3}
};

/**
 * Answers array for tests.
 */
const struct equation_sol test_sol[TESTNUMB] = {
	{0, 0, INF_SOL},
	{0, 0, NO_SOL},
	{-1, 0, ONE_SOL},
	{-99.626657, 0.313526, TWO_SOL},
	{-5, 0, TWO_SOL},
	{0, 0, NO_SOL},
	{0, 0, NO_SOL},
	{0, 0, NO_SOL},
	{2.514053, -3.778759, TWO_SOL},
	{-4.88411, 8.65462, TWO_SOL}
};

enum test_state {
	FAILED = 0,
	OK = 1
};
/**
 * Conducts several tests with ready data.
 *
 * @return 0 if there were no mistakes overwise returns 1.
 */
int set_of_tests();

/**
 * @brief make one test with input parametrs.
 *
 * @return 0 if test success, overwise returns 1.
 */
int test(int n, struct coefficients coeffs, struct equation_sol answ_sol);

/**
 * @brief Sets stdin text color 
 */
void setColor(int col);
/**
 * @brief Prints colorful text "OK" or "FAILED". 
 *
 * @param ok 1 if test was successful overwise 0.
 * @param Test number.
 */
void print_test_state(int ok, int n);
#endif //UNITTEST_H
