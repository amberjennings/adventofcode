#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[64];
	int literal = 0;
	int value = 0;
	int index, actual;

	while (fgets(input, sizeof(input), file)) {
		input[strcspn(input, "\n")] = '\0';

		literal += strlen(input);
		actual = 2;

		for (index = 0; index < (int) strlen(input); ++index) {
			if (input[index] == '\\' || input[index] == '"') {
				actual += 2;
			} else {
				actual += 1;
			}
		}
		value += actual;
	}

	fprintf(stdout, "%d\n", value - literal);
	fclose(file);
	return EXIT_SUCCESS;
}
