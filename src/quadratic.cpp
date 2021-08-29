#include <stdio.h>

#include "../headers/input.h"
#include "../headers/output.h"
#include "../headers/unittest.h"

enum run_mode {
	UNITTEST_MODE = 0,
	DEFAULT_MODE = 1
};
int main(int argc, char *argv[])
{

	int mode = DEFAULT_MODE;

	while ((--argc > 0 && (*++argv)[0] == '-')) {
		int param = 0;
		while ((param = *++argv[0]))
			switch (param) {
			case 't':
				mode = 0;
				break;
			case 'h' :
				printf("Usage: ./quadratic [parametr]\n"
					"Parametres :\n"
					"[-h] - help\n"
					"[-t] - start unitest\n");
				return 0;
				break;
			default:
				fprintf(stderr, "invalid parametr \"%c\"\n",  param);
				break;
		}
	}


	if (mode) {
		printf("Enter coefficients a, b, c: \n");
		
		struct coefficients coeffs = {{0}, 3};
		//double a = 0, b = 0, c = 0;
		/*
		if (!read_coefficient(&a) || !read_coefficient(&b) || !read_coefficient(&c)) {
			fprintf(stderr, "invalid input\n");
			clearStdin();
			return -1;
		}
		clearStdin();
		*/
		readAllCoeffs(&coeffs);
	/*	struct coefficients coeffs = {
			.a = a,
			.b = b,
			.c = c
		};*/

		struct equation_sol sol = {
			.x1   = 0, 
			.x2   = 0, 
			.type = NO_SOL
		};	

		if (solve(&coeffs, &sol) != 0)
			fprintf(stderr,"%s\n", errmsg(ERRTYPE));


		int err = print_roots(&sol);
		if (err != 0) 
			printf("%s\n", errmsg(err));
	} else {
		set_of_tests();
	}
	return 0;
}
