#include <stdio.h>

#include "input.h"
#include "output.h"
#include "unittest.h"


int main(int argc, char *argv[])
{

	run_mode mode = DEFAULT_MODE;

	while ((--argc > 0 && (*++argv)[0] == '-')) {
		
		int param = 0;
		while ((param = *++argv[0])) {
			switch (param) {
			case 't':
				mode = UNITTEST_MODE;
				break;
			case 'h' :
				printf("Usage: ./quadratic [parametr]\n"
					"Parameters :\n"
					"[-h] - help\n"
					"[-t] - start unitest\n"
					"If you entered no parameters, program start reading coefficients from stdin.\n");
				return 0;
				break;
			default:
				fprintf(stderr, "invalid parametr \"%c\"\n",  param);
				break;
			}
		}
	}


	if (mode) {
		printf("Enter coefficients a, b, c: \n");
		
		struct coefficients coeffs = {{0}, 3};
		readCoeffs(&coeffs);

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
