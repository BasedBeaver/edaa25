#include <stdio.h>
#include <math.h>

int main(void)
{
                int     i;

                printf("%10s%10s%10s\n", "x", "sqrt(x)", "exp(x)");
                for (i = 0; i <= 3; i++) {
                        double x = i/10.0;
                        printf("%10.5lf%10.5lf%10.5lf\n", x, sqrt(x), exp(x));
                }
                return 0;
}
