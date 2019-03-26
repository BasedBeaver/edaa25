#include <stdio.h>

int gcd(int a, int b)
{
        int tmp;
        int rem;

        if (a < b) {
                tmp = a;
                a = b;
                b = tmp;
        }

        rem = a % b;
        while (rem != 0) {
                a = b;
                b = rem;
                rem = a % b;
        }
        return b;
}

int main(void)
{
        int p = 243;
        int q = 173;
        if (gcd(p,q) == 1){
                printf("%d and %d are coprime.\n", p, q);
        }
        return 0;
}
