#include "output.h"

int print_roots(struct equation_sol *s)
{
   	if (s == NULL)
		return ADDR_ERR;	
        switch (s->type) {
        case INF_SOL:
                printf("Infinite solutions\n");
                break;
        case NO_SOL:
                printf("No solutions\n");
                break;
        case ONE_SOL:
                printf("Solution: %f\n", s->x1);
                break;
        case TWO_SOL:
                printf("Solutions: %f, %f\n", s->x1, s-> x2);
                break;
        default:
                fprintf(stderr,"invalid state\n");
                break;
        }
	return 0;
}
