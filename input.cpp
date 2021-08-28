#include "input.h"

int read_coefficient(double *c)
{
        assert(c);

        char inputstr[MAXLEN] = {0};
        char *ptr = NULL;

        scanf("%s", inputstr);

        errno = 0;

        *c = strtod(inputstr, &ptr);
        if (errno != 0 || *ptr != '\0') {
                fprintf(stderr,"value could not be represented as a double exactly\n");
                return 0;
        }

        return 1;
}

void clearStdin() 
{
	int c;
	while((c = getchar()) != EOF && c != '\n')
		;
}
