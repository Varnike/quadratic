/**
 * @file
 * Functions for reading coefficients from stdin.
 * @author Varnike
 * @date 28 Aug, 16:13 UTC+5
 */

#ifndef INPUT_H
#define INPUT_H

#include "arithmetics.h"
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


/**
 * %MAXLEN: maximum input length.
 */
const int MAXLEN = 100;

/**
 * Reads coefficients from stdin.
 *
 * Checks input. If input value can be represented as double exactly,
 * reads it to coeff and returns 1. Overwise prints error mesage and
 * returns 0.
 *
 * @param coeff Pointer to coefficient.
 *
 * @return 1 if input data is valid, overwise returns 0. 
 */
int read_coefficient(double *coeff);

/**
 * Clears stdin buffer.
 */
void clearStdin();
/**
 * @brief Reads all coefficients from stdin to coeff.
 *
 * @param coeff Pointer to coefficients structure.
 *
 * @return 1 if input data is valid and all coefficients written, overwise reurns 0.
 */
int readAllCoeffs(struct coefficients *coeff);
#endif
