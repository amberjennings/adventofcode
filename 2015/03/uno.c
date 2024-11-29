#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 1000

int visited[GRID_SIZE][GRID_SIZE] = {0};

int translate(int, int);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char directions[10000];
	int x = 0, y = 0, index;
	long unique = 0;

	fgets(directions, sizeof(directions), file);

	visited[GRID_SIZE / 2][GRID_SIZE / 2] = 1;

	for (index = 0; directions[index] != '\0'; ++index) {
		if (directions[index] == '>') ++x;
		if (directions[index] == '<') --x;
		if (directions[index] == '^') ++y;
		if (directions[index] == 'v') --y;

		visited[x + GRID_SIZE / 2][y + GRID_SIZE / 2] = 1;
	}

	for (x = 0; x < GRID_SIZE; ++x) {
		for (y = 0; y < GRID_SIZE; ++y) {
			if (visited[x][y]) {
				++unique;
			}
		}
	}

	fprintf(stdout, "%ld\n", unique);
	fclose(file);
	return EXIT_SUCCESS;
}

int translate(int x, int y) {
	return (x + GRID_SIZE / 2) + (y + GRID_SIZE / 2) * GRID_SIZE;
}
