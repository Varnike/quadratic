/**
 * @file
 * Set of functions for testing the program.
 * @author Varnike
 * @date 28 Aug 16:17 UTC+5
 */

#ifndef UNITTEST_H
#define UNITTEST_H


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"
#define BLU   "\x1B[34m"

#include "arithmetics.h"

const int TESTNUMB = 10;

/**
 * coefficients array for tests.
 */
const struct coefficients test_coeffs[TESTNUMB] = {
	{0, 0, 0},
	{0, 0, 1},
	{0, 1, 1},
	{99, 9832, -3092.32},
	{9, 45, 0},
	{0, 0, -9},
	{7, 7, 7},
	{101, 4, 88},
	{-34, -43, 323},
	{23.4, -88.23, -989.12}
};

/**
 * answers array for tests.
 */
const struct solution test_sol[TESTNUMB] = {
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

/**
 * conducts several tests with ready data.
 *
 * @return 0 if there were no mistakes overwise returns 1.
 */
int set_of_tests();

/**
 * make one test with input parametrs.
 *
 * @return 0 if test success, overwise returns 1.
 */
int test(int n, struct coefficients coeffs, struct solution answ_sol);

#endif //UNITTEST_H
