#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	while((c = getchar()) != EOF) {

		int length = 0;
		int size = 10;
		char* char_ptr;
		char* first;
		list = malloc(sizeof(char) * 10);
		first = list; //is this how pointers work?
		if (char_ptr == NULL) {
			exit(1);
		}

		if (isalpha(c)) {
			if (length >= size) {
				list = realloc(list, size*2);
				if (list == NULL) {
					exit(1);
				}

				size = size*2;
				&char_ptr = c;
				char_ptr++;
				length++;

			}
			printf("%c", (char)(c));
		}
		if (!isalpha(c)) {
			printf("\n");
		}
	}
	return 0;
}
