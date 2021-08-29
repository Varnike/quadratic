#include <stdio.h>

#include "input.h"
#include "output.h"
#include "unittest.h"

int main(int argc, char *argv[])
{
	int mode = 1;

	int c = 0;
	while ((--argc > 0 && (*++argv)[0] == '-')) {
		while ((c = *++argv[0]))
			switch (c) {
			case 't':
				mode = 0;
				break;
			case 'h' :
				printf("Usage:\n"
					"[-h] - help\n"
					"[-t] - start unitest\n");
				break;
			default:
				fprintf(stderr, "invalid parametr %c\n",  c);
				break;
		}
	}


	if (mode) {
		printf("Enter coefficients a, b, c: \n");

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
			.x1   = 0, 
			.x2   = 0, 
			.type = NO_SOL
		};	

		if (solve(&coeffs, &sol) != 0)
			fprintf(stderr,"%s\n", errmsg(errtype));


		int err = print_roots(&sol);
		if (err != 0) 
			printf("%s\n", errmsg(err));
	} else {
		set_of_tests();
	}
	return 0;
}

