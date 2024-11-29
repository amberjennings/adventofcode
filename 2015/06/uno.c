#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 1000

int lights[GRID_SIZE][GRID_SIZE] = {0};

void process(char *);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char instruction[64];
	int x, y;
	int on = 0;

	while (fgets(instruction, sizeof(instruction), file)) process(instruction);

	for (x = 0; x < GRID_SIZE; ++x) {
		for (y = 0; y < GRID_SIZE; ++y) {
			on += lights[x][y];
		}
	}

	fprintf(stdout, "%d\n", on);
	fclose(file);
	return EXIT_SUCCESS;
}

void process(char *instruction) {
	int x, y, x1, y1, x2, y2;

	if (sscanf(instruction, "turn on %d,%d through %d,%d", &x1, &y1, &x2, &y2) == 4) {
		for (x = x1; x <= x2; ++x) {
			for (y = y1; y <= y2; ++y) {
				lights[x][y] = 1;
			}
		}
	} else if (sscanf(instruction, "turn off %d,%d through %d,%d", &x1, &y1, &x2, &y2) == 4) {
		for (x = x1; x <= x2; ++x) {
			for (y = y1; y <= y2; ++y) {
				lights[x][y] = 0;
			}
		}
	} else if (sscanf(instruction, "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2) == 4) {
		for (x = x1; x <= x2; ++x) {
			for (y = y1; y <= y2; ++y) {
				lights[x][y] = 1 - lights[x][y];
			}
		}
	}
}
