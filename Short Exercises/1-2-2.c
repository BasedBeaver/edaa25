#include <stdio.h>

int unsigned_short_func()
{
        unsigned short value = ~0;
        int bits = 0;
        while (value) {
                value >>= 1;
                bits++;
        }
        printf("Number of bits in an unsigned short: %d\n", bits);
}

int unsigned_int_func()
{
        unsigned int value = ~0;
        int bits = 0;
        while (value) {
                value >>= 1;
                bits++;
        }
        printf("Number of bits in an unsigned int: %d\n", bits);
}

int unsigned_long_func()
{
        unsigned long value = ~0;
        int bits = 0;
        while (value) {
                value >>= 1;
                bits++;
        }
        printf("Number of bits in an unsigned long: %d\n", bits);
}

int unsigned_long_long_func()
{
        unsigned long long value = ~0;
        int bits = 0;
        while (value) {
                value >>= 1;
                bits++;
        }
        printf("Number of bits in an unsigned long long: %d\n", bits);
}

int main(void)
{
        unsigned_short_func();
        unsigned_int_func();
        unsigned_long_func();
        unsigned_long_long_func();
        return 0;
}
