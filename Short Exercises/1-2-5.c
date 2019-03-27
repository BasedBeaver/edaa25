#include <stdio.h>
#include <stdbool.h>

bool leap_year(unsigned short int year)
{
        //return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        int     four = 0;
        int     hundred = 0;
        int     fhundred = 0;
        if (year % 4 == 0) {
                four = 1;
        }
        if (year % 100 == 0) {
                hundred = 1;
        }
        if (year % 400 == 0) {
                fhundred = 1;
        }

        if (four == 1 && fhundred == 1){
                return 1;
        }
        if (four == 1 && hundred != 1) {
                return 1;
        }
        return 0;
}

int main(void)
{
        int i = 1989;
        bool b = leap_year(i);
        if (b) {
                printf("The year %d is a leap year\n", i);
        }
        else {
                printf("The year %d is not a leap year\n", i);
        }
        return 0;
}
