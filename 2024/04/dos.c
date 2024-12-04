#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 140

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char grid[SIZE + 1][SIZE + 1];
	int count = 0, index;
	int x, y;

	for (index = 0; index < SIZE; ++index) {
		fgets(grid[index], sizeof(grid[index]) + 1, file);
	}

	for (x = 0; x < SIZE; ++x) {
		for (y = 0; y < SIZE; ++y) {
			if (grid[x][y] == 'A') {
				if (x - 1 >= 0 && y - 1 >= 0 &&
					x + 1 < SIZE && y + 1 <= SIZE) {
					if (grid[x - 1][y - 1] == 'M' &&
						grid[x + 1][y + 1] == 'S' &&
						grid[x + 1][y - 1] == 'M' &&
						grid[x - 1][y + 1] == 'S') {
						++count;
					} else if (grid[x - 1][y - 1] == 'S' &&
						grid[x + 1][y + 1] == 'M' &&
						grid[x + 1][y - 1] == 'S' &&
						grid[x - 1][y + 1] == 'M') {
						++count;
					} else if (grid[x - 1][y - 1] == 'M' &&
						grid[x + 1][y + 1] == 'S' &&
						grid[x + 1][y - 1] == 'S' &&
						grid[x - 1][y + 1] == 'M') {
						++count;
					} else if (grid[x - 1][y - 1] == 'S' &&
						grid[x + 1][y + 1] == 'M' &&
						grid[x + 1][y - 1] == 'M' &&
						grid[x - 1][y + 1] == 'S') {
						++count;
					}
				}
			}
		}
	}

	fprintf(stdout, "%d\n", count);
	fclose(file);
	return EXIT_SUCCESS;
}
