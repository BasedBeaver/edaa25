#include <stdio.h>

#define DEBUG(message) printf("Line [%d] - %s\n", __LINE__, message);

int main(int argc, char *argv[])
{
        printf("argc: %d\n", argc);
        for (int i = 0; i < argc; i++) {
                printf("%s\n", argv[i]);
        }
        DEBUG("test");
        return 0;
}
