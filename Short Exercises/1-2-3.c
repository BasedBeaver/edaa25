#include <stdio.h>
#include "time.h"

#define LIMIT 18

// int main(void)
// {
//         long double sum = 0;
//         unsigned int term = 0;
//
//         clock_t time = clock();
//         while (sum < LIMIT) {
//                 sum += 1.0/++term;
//         }
//         time = clock() - time;
//
//         printf("=================ORIGINAL=================\n");
//         printf("Number of terms: %u, the sum is %.10Lf\n", term, sum);
//         printf("Used time: %f\n", (double)time/CLOCKS_PER_SEC);
//         return 0;
// }

int main(void)
{
        long double sum = 0;
        unsigned int term = 1;

        clock_t time = clock();
        while (sum < LIMIT) {
                sum += 1.0/term;
                term++;
        }
        time = clock() - time;

        printf("=================C=================\n");
        printf("Number of terms: %u, the sum is %.10Lf\n", term-1, sum);
        printf("Used time: %f\n", (double)time/CLOCKS_PER_SEC);
        return 0;
}
