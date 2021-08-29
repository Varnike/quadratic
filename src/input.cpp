#include "input.h"

int read_coefficient(double *c)
{
        assert(c);

        char inputstr[MAX_BUFF_LEN] = {0};
        char *ptr = nullptr;

        scanf("%s", inputstr);

        errno = 0;

        *c = strtod(inputstr, &ptr);
        if (errno != 0 || *ptr != '\0') {
                fprintf(stderr,"\"%s\": value could not be represented as a double exactly\n", inputstr);
                return 0;
        }

        return 1;
}

void clearStdin() 
{
	int c = 0;
	while((c = getchar()) != EOF && c != '\n')
		;
}

int readCoeffs(struct coefficients *coeff)
{
	for (size_t i = 0; i != coeff->coeff_n; i++) {
		if (!read_coefficient(&coeff->val[i])) {
			clearStdin();
			return 0;
		}
	}
	clearStdin();

	return 1;
}
