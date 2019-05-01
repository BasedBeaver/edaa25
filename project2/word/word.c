#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	while((c = getchar()) != EOF) {
		printf("%c\n", (char)(c));
	}
	return 0;
}
