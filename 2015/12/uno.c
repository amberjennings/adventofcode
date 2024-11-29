#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[65535];
	char *token;
	int total = 0;
	int index;

	fgets(input, sizeof(input), file);

	for (index = 0; input[index] != '\0'; ++index) {
		if (!isdigit(input[index])) {
			if (input[index] == '-' && isdigit(input[index + 1])) continue;
			else input[index] = ' ';
		}
	}

	token = strtok(input, " ");

	while (token) {
		total += atoi(token);
		token = strtok(NULL, " ");
	}

	fclose(file);
	fprintf(stdout, "%d\n", total);
	return EXIT_SUCCESS;
}
