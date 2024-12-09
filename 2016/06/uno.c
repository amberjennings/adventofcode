#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("input.txt", "r");
    char input[8][26] = {0};
	char out[9] = {0};
    int index, jndex, max;

	while (fscanf(file, "%s", out) != EOF) {
		for (index = 0; index < 8; ++index)
			++input[index][out[index] - 'a'];
	}

	for (index = 0; index < 8; ++index) {
		max = 0;
		for (jndex = 0; jndex < 26; ++jndex) {
			if (input[index][jndex] > input[index][max])
				max = jndex;
		}
		out[index] = 'a' + max;
	}

    fclose(file);
	fprintf(stdout, "%s\n", out);
    return EXIT_SUCCESS;
}
