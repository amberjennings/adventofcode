#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[100];
	int index, start, pair, repeat;
	int good = 0;

	while (fgets(input, sizeof(input), file)) {
		input[strcspn(input, "\n")] = '\0';

		pair = 0;
		repeat = 0;

		for (index = 0; input[index] != '\0'; ++index) {
			for (start = index + 2; input[start] != '\0'; ++start) {
				if (input[index] == input[start] && input[index + 1] == input[start + 1]) {
					pair = 1;
					break;
				}
			}
			if (pair) break;
		}

		for (index = 0; input[index + 2] != '\0'; ++index) {
			if (input[index] == input[index + 2]) {
				repeat = 1;
				break;
			}
		}

		if (pair && repeat) {
			++good;
		}
	}

	fprintf(stdout, "%d\n", good);
	fclose(file);
	return EXIT_SUCCESS;
}
