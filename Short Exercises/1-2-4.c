#include "stdio.h"

unsigned int hex_digit_sum(unsigned int value)
{
        unsigned int sum = 0;
        while (value > 0) {
                unsigned int tmp = value & 0xf; //tmp is the int repesentation
                                                // of the 4 right hand bits
                printf("tmp: %u\n", tmp);
                sum += tmp;
                value >>= 4;
        }
        return sum;
}

int main(void)
{
        unsigned int res = hex_digit_sum(166);
        printf("%d\n", res);
        return 0;
}
