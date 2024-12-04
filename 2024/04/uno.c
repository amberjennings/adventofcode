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
		if (grid[x][y] == 'X') {
			if (x + 3 < SIZE &&
				grid[x + 1][y] == 'M' &&
				grid[x + 2][y] == 'A' &&
				grid[x + 3][y] == 'S')
				++count;
			if (x + 3 < SIZE && y + 3 < SIZE &&
				grid[x + 1][y + 1] == 'M' &&
				grid[x + 2][y + 2] == 'A' &&
				grid[x + 3][y + 3] == 'S')
				++count;
			if (y + 3 < SIZE &&
				grid[x][y + 1] == 'M' &&
				grid[x][y + 2] == 'A' &&
				grid[x][y + 3] == 'S')
				++count;
			if (x - 3 >= 0 && y + 3 < SIZE &&
				grid[x - 1][y + 1] == 'M' &&
				grid[x - 2][y + 2] == 'A' &&
				grid[x - 3][y + 3] == 'S')
				++count;
			if (x - 3 >= 0 &&
				grid[x - 1][y] == 'M' &&
				grid[x - 2][y] == 'A' &&
				grid[x - 3][y] == 'S')
				++count;
			if (x - 3 >= 0 && y - 3 >= 0 &&
				grid[x - 1][y - 1] == 'M' &&
				grid[x - 2][y - 2] == 'A' &&
				grid[x - 3][y - 3] == 'S')
				++count;
			if (y - 3 >= 0 &&
				grid[x][y - 1] == 'M' &&
				grid[x][y - 2] == 'A' &&
				grid[x][y - 3] == 'S')
				++count;
			if (x + 3 < SIZE && y - 3 >= 0 &&
				grid[x + 1][y - 1] == 'M' &&
				grid[x + 2][y - 2] == 'A' &&
				grid[x + 3][y - 3] == 'S')
				++count;
			}
		}
	}

	fprintf(stdout, "%d\n", count);
	fclose(file);
	return EXIT_SUCCESS;
}
