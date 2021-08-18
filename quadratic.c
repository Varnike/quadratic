#include "solve.h"
struct solution solve(double , double , double );
void print(struct solution *);
int main(int argc, char *argv[])
{
	double x0, x1, x2;
	scanf("%lf%lf%lf", &x2, &x1, &x0);
	struct solution s = solve(x2, x1, x0);
	print(&s);
}

