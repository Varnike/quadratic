#include "unittest.h"

int test(int n, struct coefficients coeffs, struct solution answ_sol)
{ 
	struct solution sol = {
		.x1   = 0,
		.x2   = 0,
		.type = NO_SOL
	};

	solve(&coeffs, &sol);

	if (sol.type != answ_sol.type) {
		printf("Test #%d " RED "FAILED:" RESET" wrong answer type, programm answ: %d,"
				" right: %d\n", n, sol.type, answ_sol.type);
		return 1;
	} else {
		switch (answ_sol.type) {
		case NO_SOL:
			printf("Test #%d:" GRN " OK\n" RESET, n);
			return 0;
			break;
		case ONE_SOL:
			if (cmp_double(answ_sol.x1, sol.x1) == EQUAL) {
				printf("Test #%d:" GRN " OK\n" RESET, n);
				return 0;
			} else {
				printf("Test #%d" RED "FAILED:" RESET " wrong answer: program"
					" answer %f, right answer %f\n", n, sol.x1, answ_sol.x1);
				return 1;
			}
			break;
		case TWO_SOL:
			if (cmp_double(answ_sol.x1, sol.x1) == EQUAL 
				&& cmp_double(answ_sol.x2, sol.x2) == EQUAL) {
				 printf("Test #%d:" GRN " OK\n" RESET, n);
				 return 0;
			} else {
				printf("Test #%d " RED "FAILED: " RESET "wrong answer: program "
					"answers %f and %f, right answers %f and %f\n",
				        n, sol.x1, sol.x2, answ_sol.x1,answ_sol.x2);
				return 1;
			}
			break;
		case INF_SOL:
			printf("Test #%d:" GRN " OK\n" RESET, n);
			return 0;
                        break;
		}
	}
	return 1;
}

int set_of_tests()
{
	int fails = 0;

	for (int i = 0; i < TESTNUMB; i++) {
		if (test(i + 1, test_coeffs[i], test_sol[i] ) == 1)
			fails++;
	}
	/*
	char col[2][3] = {0};
	int cred = 255 * (double)(fails / TESTNUMB);
	int cgreen = 255 * (1 - (double)(fails / TESTNUMB));
	for (int i = 0; i != 3; i++) {
		if (cred) {
			col[0][i] = cred % 10;
			cred /= 10;
		}	
		if (cgreen) {
			col[1][i] = cgreen % 10;
			cgreen /= 10;
		}
	}
	printf("\033[38;2;" + col[0] + ";" + col[1] + ";0m "); 
	*/
	printf(BLU "Total: %d tests, %d fails\n" RESET, TESTNUMB, fails);

	return (fails == 0) ? 0 : 1;
}

