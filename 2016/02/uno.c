#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[1024];
	int index, index_c = 0;
	int pos[2] = { 1, 1 };
	int code[5];
	int numpad[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	while (fgets(input, sizeof(input), file)) {
		index = 0;
		while (input[index] != '\0' && input[index] != '\n') {
			if (input[index] == 'R') {
				if (pos[1] < 2) ++pos[1];
			} else if (input[index] == 'L') {
				if (pos[1] > 0) --pos[1];
			} else if (input[index] == 'D') {
				if (pos[0] < 2) ++pos[0];
			} else if (input[index] == 'U') {
				if (pos[0] > 0) --pos[0];
			}
			++index;
		}
		code[index_c] = numpad[pos[0]][pos[1]];
		++index_c;
	}

	for (index = 0; index < index_c; ++index) {
		fprintf(stdout, "%d", code[index]);
	} fprintf(stdout, "\n");

	fclose(file);
	return EXIT_SUCCESS;
}
