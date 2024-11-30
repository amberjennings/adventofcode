#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char *token;
	char input[1024];
	int loc[2] = {0, 0};
	int instruction;
	int dir = 0;

	fgets(input, sizeof(input), file);
	token = strtok(input, ", ");

	while (token) {
		if (token[0] == 'R')
			dir = (dir + 1) % 4;
		else if (token[0] == 'L')
			dir = (dir + 3) % 4;
		sscanf(token + 1, "%d", &instruction);

		if (dir == 0) loc[1] += instruction;
		else if (dir == 1) loc[0] += instruction;
		else if (dir == 2) loc[1] -= instruction;
		else loc[0] -= instruction;

		token = strtok(NULL, ", ");
	}

	fprintf(stdout, "%d\n", abs(loc[0]) + abs(loc[1]));
	fclose(file);
	return EXIT_SUCCESS;
}

