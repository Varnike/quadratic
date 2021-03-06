#include "arithmetics.h"

int errtype = 0;

int linear(const double b, const double c, struct solution *s)
{
        if (s == NULL) {
		errtype = ADDR_ERR;
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

int quadratic_roots(const struct coefficients *coeff, double d, struct solution *s)
{
        if (coeff == NULL || s == NULL) {
		errtype = ADDR_ERR;
                return ADDR_ERR;
	}

        s->x1 = (-coeff->b - sqrt(d)) / (2 * coeff->a);
        s->x2 = (-coeff->b + sqrt(d)) / (2 * coeff->a);
	return 0;
}

int quadratic(const struct coefficients *coeff, struct solution *s)
{
        if (coeff == NULL || s == NULL) {
		errtype = ADDR_ERR;
                return ADDR_ERR;
	}
	
	if (cmp_to_zero(coeff->c)) {
		linear(coeff->a, coeff->b, s);
		s->x2 = 0;
		s->type = TWO_SOL;
		return 0;
	}

        double d = discr(coeff->a, coeff->b, coeff->c);
        if (cmp_double(d, 0) == LESS) {
                s->type = NO_SOL;
        } else {
                s->type = TWO_SOL;
                errtype = quadratic_roots(coeff, d, s);
		return errtype;
        }

	return 0;
}

int solve(const struct coefficients *coeff, struct solution *s)
{
        if (coeff == NULL || s == NULL) {
		errtype = ADDR_ERR;
                return ADDR_ERR;
	}

	if (!isfinite(coeff->a) || !isfinite(coeff->b) || !isfinite(coeff->c)) {
		errtype = DOUBLE_ERR;
                return DOUBLE_ERR;
	}

	errtype = 0;	
        if (cmp_to_zero(coeff->a)) {
		linear(coeff->b, coeff->c, s);
	} 
	else {
		quadratic(coeff, s);
	}
	
	return errtype;
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
	/*
	switch (errt) {
	case NO_ERR:
		strcpy(msg, "no errors");
		break;
	case ADDR_ERR:
		strcpy(msg, "NULL pointer error!");
		break;
	case DOUBLE_ERR:
		strcpy(msg, "invalid double value error!");
		break;
	default:
		strcpy(msg, "wrong error type error!");
		break;
	}
	return msg;
	*/
}
