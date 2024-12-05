#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[24576];
	char trash;
	int len;
	int l, r;
	int index;
	int sum = 0;
	int mul = 1;

	fread(input, 1, sizeof(input), file);
	len = strlen(input);

	for (index = 0; index < len; ++index) {
		l = 0;
		r = 0;
		if (!strncmp(input + index, "do()", 4)) mul = 1;
		if (!strncmp(input + index, "don't()", 7)) mul = 0;
		if (strncmp(input + index, "mul(", 4) == 0) {
			index += 4;
			sscanf(input + index, "%d,%d%c", &l, &r, &trash);
			if (trash != ')') l = 0;
		} if (mul) sum += l * r;
	}

	fprintf(stdout, "%d\n", sum);
	fclose(file);
	return EXIT_SUCCESS;
}
