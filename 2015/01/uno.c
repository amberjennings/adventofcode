#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char ch;
	long floor = 0;

	while ((ch = fgetc(file)) != EOF) {
		if (ch == '(') floor += 1;
		else if (ch == ')') floor -= 1;
	}

	fprintf(stdout, "%ld\n", floor);
	fclose(file);
	return EXIT_SUCCESS;
}
