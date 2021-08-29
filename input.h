/**
 * @file
 * functions for reading coefficients from stdin 
 * @author Varnike
 * @date 28 Aug, 16:13 UTC+5
 */

#ifndef INPUT_H
#define INPUT_H

#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


/**
 * %MAXLEN: maximum input length.
 */
const int MAXLEN = 100;

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
 * clears stdin buffer
 */
void clearStdin();
#endif
