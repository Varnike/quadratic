#include "solve.h"

int main(int argc, char *argv[])
{
	double x0 = 0, x1 = 0, x2 = 0;
	if (!read_coefficient(&x2) || !read_coefficient(&x1) || !read_coefficient(&x0)) {
		fprintf(stderr, "invalid input\n");
		return -1;
	}

	struct solution sol;
	solve(x2, x1, x0, &sol);

	print_roots(&sol);

	return 0;
}

