/**
 * @file
 * Set of functions for printing equation_sol of quadratic equasion
 * @author Varnike
 * @date 28 Aug 16:17 UTC+5
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "arithmetics.h"

/**
 * Prints equasion roots.
 *
 * Prints equasion roots depending on sol state.
 *
 * @param sol pointer to equation_sol structure.
 */
int print_roots(struct equation_sol *sol);

#endif //OUTPUT_H
