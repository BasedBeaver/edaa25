#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int c;
	int length = 0;
	int size = 10;

	char* curr_word = malloc(sizeof(char) * size);
	char* longest_word = malloc(sizeof(char) * size);
	if (curr_word == NULL || longest_word == NULL) {
		exit(1);
	}

	int curr_longest = 0;
	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			if (length >= size) {
				size *= 2;
				curr_word = realloc(curr_word, sizeof(char) * size);
				if (curr_word == NULL) {
					exit(1);
				}
			}
			curr_word[length++] = c;
		}
		if (!isalpha(c)) {
			if (length > curr_longest) {
				longest_word = realloc(longest_word, sizeof(char) * length);
				memcpy(longest_word, curr_word, length);
				curr_longest = length;
			}
			length = 0;
		}
	}
	printf("%d characters in longest word: %s\n", curr_longest, longest_word);
	free(curr_word);
	free(longest_word);
	return 0;
}
