#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 1000

int visited[GRID_SIZE][GRID_SIZE] = {0};

int translate(int, int);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char directions[10000];
	int x, y, s_x, s_y, r_x, r_y, index;
	long unique = 0;

	fgets(directions, sizeof(directions), file);

	visited[GRID_SIZE / 2][GRID_SIZE / 2] = 1;

	for (index = 0; directions[index] != '\0'; ++index) {
		if (index % 2 == 0) {
			if (directions[index] == '>') ++s_x;
			if (directions[index] == '<') --s_x;
			if (directions[index] == '^') ++s_y;
			if (directions[index] == 'v') --s_y;
			visited[s_x + GRID_SIZE / 2][s_y + GRID_SIZE / 2] = 1;
		} else {
			if (directions[index] == '>') ++r_x;
			if (directions[index] == '<') --r_x;
			if (directions[index] == '^') ++r_y;
			if (directions[index] == 'v') --r_y;
			visited[r_x + GRID_SIZE / 2][r_y + GRID_SIZE / 2] = 1;
		}
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
