#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char ch;
	long floor = 0;
	long count = 0;

	while ((ch = fgetc(file)) != EOF) {
		if (floor != -1) {
			if (ch == '(') floor += 1;
			else if (ch == ')') floor -= 1;
			count += 1;
		} else {
			fprintf(stdout, "%ld\n", count);
			return EXIT_SUCCESS;
		}
	}

	fprintf(stdout, "%ld\n", floor);
	fclose(file);
	return EXIT_SUCCESS;
}
