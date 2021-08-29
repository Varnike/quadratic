#include "unittest.h"

int test(int n, struct coefficients coeffs, struct equation_sol answ_sol)
{ 
	struct equation_sol sol = {
		.x1   = 0,
		.x2   = 0,
		.type = NO_SOL
	};

	solve(&coeffs, &sol);

	if (sol.type != answ_sol.type) {
		print_test_state(FAILED, n);
		printf(" wrong answer type, programm answ: %d,"
			" right: %d\n", sol.type, answ_sol.type);
		return 1;
	} else {
		switch (answ_sol.type) {
		case NO_SOL:
			print_test_state(OK, n);
			return 0;
			break;
		case ONE_SOL:
			if (cmp_double(answ_sol.x1, sol.x1) == EQUAL) {
				print_test_state(OK, n);
				return 0;
			} else {
				print_test_state(FAILED, n);
				printf(" wrong answer: program"
					" answer %f, right answer %f\n", sol.x1, answ_sol.x1);
				return 1;
			}
			break;
		case TWO_SOL:
			if (cmp_double(answ_sol.x1, sol.x1) == EQUAL 
				&& cmp_double(answ_sol.x2, sol.x2) == EQUAL) {
				 print_test_state(OK, n);
				 return 0;
			} else {
				print_test_state(FAILED, n);
				printf(" wrong answer: program answers %f and %f,"
					" right answers %f and %f\n",
				        sol.x1, sol.x2, answ_sol.x1,answ_sol.x2);
				return 1;
			}
			break;
		case INF_SOL:
			print_test_state(OK, n);
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
	
	setColor(BLU);
	printf("Total: %d tests, %d fails\n",  TESTNUMB, fails);
	setColor(DEFAULT);

	return (fails == 0) ? 0 : 1;
}

void setColor(int col) 
{
	switch (col) {
	case RED:
		printf("\x1B[31m");
		break;
	case GRN:
		printf("\x1B[32m");
		break;
	case BLU:
		printf("\x1B[0m");
		break;
	case DEFAULT:
		printf("\x1B[0m");
		break;
	default:
		printf("\x1B[0m");
		break;
	}
}

void print_test_state(int ok, int n)
{
	printf("Test #%d: ", n);
	if (ok == OK) {
		setColor(GRN);
		printf("OK\n");
		setColor(DEFAULT);
	}
	else {
		setColor(RED);
		printf("FAILED: ");
		setColor(DEFAULT);
	}
}
