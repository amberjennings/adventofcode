#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("input.txt", "r");
    char input[8][26] = {0};
	char out[9] = {0};
    int index, jndex, min;

	while (fscanf(file, "%s", out) != EOF) {
		for (index = 0; index < 8; ++index)
			++input[index][out[index] - 'a'];
	}

	for (index = 0; index < 8; ++index) {
		min = 0;
		for (jndex = 0; jndex < 26; ++jndex) {
			if (input[index][jndex] < input[index][min])
				min = jndex;
		}
		out[index] = 'a' + min;
	}

    fclose(file);
	fprintf(stdout, "%s\n", out);
    return EXIT_SUCCESS;
}
