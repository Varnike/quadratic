#include "solve.h"

int main(int argc, char *argv[])
{
	double a = 0, b = 0, c = 0;
	if (!read_coefficient(&a) || !read_coefficient(&b) || !read_coefficient(&c)) {
		fprintf(stderr, "invalid input\n");
		return -1;
	}

	struct solution sol = {0, 0, NO_SOL};
	solve(a, b, c, &sol);

	print_roots(&sol);

	return 0;
}

