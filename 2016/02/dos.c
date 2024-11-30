#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[1024];
	int index, index_c = 0;
	int pos[2] = { 2, 0 };
	char code[10];
	char numpad[5][5] = {
		{ '\0', '\0', '1', '\0', '\0' },
		{ '\0', '2', '3', '4', '\0' },
		{ '5', '6', '7', '8', '9' },
		{ '\0', 'A', 'B', 'C', '\0' },
		{ '\0', '\0', 'D', '\0', '\0' }
	};

	while (fgets(input, sizeof(input), file)) {
		index = 0;
		while (input[index] != '\0' && input[index] != '\n') {
			if (input[index] == 'R') {
				if (pos[1] < 4 && numpad[pos[0]][pos[1] + 1] != '\0')
					++pos[1];
			} else if (input[index] == 'L') {
				if (pos[1] > 0 && numpad[pos[0]][pos[1] - 1] != '\0')
					--pos[1];
			} else if (input[index] == 'D') {
				if (pos[0] < 4 && numpad[pos[0] + 1][pos[1]] != '\0')
					++pos[0];
			} else if (input[index] == 'U') {
				if (pos[0] > 0 && numpad[pos[0] - 1][pos[1]] != '\0') --pos[0];
			}
			++index;
		}
		code[index_c] = numpad[pos[0]][pos[1]];
		++index_c;
	}

	for (index = 0; index < index_c; ++index) {
		fprintf(stdout, "%c", code[index]);
	} fprintf(stdout, "\n");

	fclose(file);
	return EXIT_SUCCESS;
}
