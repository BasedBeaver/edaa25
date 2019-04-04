#include <stdio.h>
#include <stdbool.h>

int sum_divisors(int nbr)
{
        int     i;
        int     sum = 0;

        for (i = 1; i <= nbr/2; i++) {
                if (nbr % i == 0) {
                        sum += i;
                }
        }
        return sum;
}

bool perfect(int nbr)
{
        return sum_divisors(nbr) == nbr;
}

int main(void)
{
        int     x;
        for (x = 1; x < 10000; x++) {
                if (perfect(x)) {
                        printf("%d\n", x);
                }
        }
        return 0;
}
