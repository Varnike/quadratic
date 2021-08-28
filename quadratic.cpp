#include <stdio.h>

#include "input.h"
#include "output.h"
#include "unittest.h"

int main(void)
{
	int mode = 0;
	scanf("%d", &mode);
	if(mode) {
		double a = 0, b = 0, c = 0;
		if (!read_coefficient(&a) || !read_coefficient(&b) || !read_coefficient(&c)) {
			fprintf(stderr, "invalid input\n");
			clearStdin();
			return -1;
		}
		clearStdin();
		struct coefficients coeffs = {
			.a = a,
			.b = b,
			.c = c
		};

		struct solution sol = {
			.x1 = 0, 
			.x2 = 0, 
			.type = NO_SOL
		};	
		if (solve(&coeffs, &sol) != 0)
			printf("%s\n", errmsg(errtype));

		int err = print_roots(&sol);
		if(err != 0) 
			printf("%s\n", errmsg(err));
	} else {
		set_of_tests();
	}
	return 0;
}

