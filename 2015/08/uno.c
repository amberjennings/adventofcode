#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[64];
	int literal = 0;
	int value = 0;
	int index, actual;

	while (fgets(input, sizeof(input), file)) {
		input[strcspn(input, "\n")] = '\0';
		literal += strlen(input);
		actual = 0;

		for (index = 1; index < (int) strlen(input) - 1; ++index) {
			if (input[index] == '\\') {
				if (input[index + 1] == '\\' || input[index + 1] == '\"') {
					++actual;
					++index;
				} else if (input[index + 1] == 'x' && index + 3 < (int)
						   strlen(input) && isxdigit(input[index + 2]) &&
						   isxdigit(input[index + 3])) {
					++actual;
					index += 3;
				}
			} else ++actual;
		}
		value += actual;
	}

	fprintf(stdout, "%d\n", literal - value);
	fclose(file);
	return EXIT_SUCCESS;
}
