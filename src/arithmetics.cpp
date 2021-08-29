#include "../headers/arithmetics.h"

int ERRTYPE = 0;

int linear(const double b, const double c, struct equation_sol *s)
{
        if (s == NULL) {
		ERRTYPE = ADDR_ERR;
		return ADDR_ERR;
	}
        if (cmp_to_zero(b)) {
                if (cmp_to_zero(c))
                        s->type = INF_SOL;
                else
                        s->type = NO_SOL;
        } else {
                s->type = ONE_SOL;
                s->x1 = -(c / b);
        }
	return 0;
}

int quadratic_roots(const struct coefficients *coeff, double d, struct equation_sol *s)
{
        if (coeff == NULL || s == NULL) {
		ERRTYPE = ADDR_ERR;
                return ADDR_ERR;
	}

        s->x1 = (-coeff->val[1] - sqrt(d)) / (2 * coeff->val[0]);
        s->x2 = (-coeff->val[1] + sqrt(d)) / (2 * coeff->val[0]);
	return 0;
}

int quadratic(const struct coefficients *coeff, struct equation_sol *s)
{
        if (coeff == NULL || s == NULL) {
		ERRTYPE = ADDR_ERR;
                return ADDR_ERR;
	}
	
	if (cmp_to_zero(coeff->val[2])) {
		linear(coeff->val[0], coeff->val[1], s);
		s->x2 = 0;
		s->type = TWO_SOL;
		return 0;
	}

        double d = discr(coeff->val[0], coeff->val[1], coeff->val[2]);
        if (cmp_double(d, 0) == LESS) {
                s->type = NO_SOL;
        } else {
                s->type = TWO_SOL;
                ERRTYPE = quadratic_roots(coeff, d, s);
		return ERRTYPE;
        }

	return 0;
}

int solve(const struct coefficients *coeff, struct equation_sol *s)
{
        if (coeff == NULL || s == NULL) {
		ERRTYPE = ADDR_ERR;
                return ADDR_ERR;
	}

	if (!isfinite(coeff->val[0]) || !isfinite(coeff->val[1]) || !isfinite(coeff->val[2])) {
		ERRTYPE = DOUBLE_ERR;
                return DOUBLE_ERR;
	}

	ERRTYPE = 0;	
        if (cmp_to_zero(coeff->val[0])) {
		linear(coeff->val[1], coeff->val[2], s);
	} 
	else {
		quadratic(coeff, s);
	}
	
	return ERRTYPE;
}

double discr(const double a, const double b, const double c)
{
        return (b * b - 4 * a * c);
}

int cmp_to_zero(const double val)
{
        return (cmp_double(val, 0) == EQUAL);
}

int cmp_double(double val1, double val2)
{
	if (fabs(val1 - val2) <= ACCURACY) 
		return EQUAL;
	else 
		return (val1 - val2 < - ACCURACY) ? LESS : MORE;
}

const char *errmsg(int errt)
{
	const char *messages[] = {
		"Success",
		"NULL pointer error!",
		"invalid double value error!",
		"two pointers point at same address",
		"unknowm error type!"
	};
	if (errt >= 0 && errt <= 3)
		return messages[errt];


	return messages[UNKNOWN_ERR];
}
