#include <stdio.h>

// function declaration
int func();

int main() {

        // function call
        int i = func();
        printf("i = %i \n", i);
        return 0;
}

// function definition
int func() {
        printf("Hello there! \n");
        return 2;
}
