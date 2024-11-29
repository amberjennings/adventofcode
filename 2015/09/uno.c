#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 16

int map[MAX_LOCATIONS][MAX_LOCATIONS];
char locations[MAX_LOCATIONS][MAX_LOCATIONS];

int min = 65535;

int dfs(int, int, int, int);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[64];
	char start[32], end[32];
	int distance, x, y;
	int num_locations = 0;

	memset(map, -1, sizeof(map));

	while (fgets(input, sizeof(input), file)) {
		if (sscanf(input, "%s to %s = %d\n", start, end, &distance) == 3) {
			for (x = 0; x < num_locations; ++x) {
				if (strcmp(locations[x], start) == 0) break;
			}
			if (x == num_locations) {
				strcpy(locations[num_locations], start);
				x = num_locations++;
			}
			for (y = 0; y < num_locations; ++y) {
				if (strcmp(locations[y], end) == 0) break;
			}
			if (y == num_locations) {
				strcpy(locations[num_locations], end);
				y = num_locations++;
			}

			map[x][y] = map[y][x] = distance;
		}
	}
	for (x = 0; x < num_locations; ++x) dfs(x, 0, 0, num_locations);

	fprintf(stdout, "%d\n", min);
	fclose(file);
	return EXIT_SUCCESS;
}

int dfs(int loc, int state, int distance, int num_locations) {
	int index;
	state = state | (1 << loc);

	if (state == (1 << num_locations) - 1) {
		if (distance < min) min = distance;
		return EXIT_SUCCESS;
	}

	for (index = 0; index < MAX_LOCATIONS; ++index) {
		if (map[loc][index] == -1) continue;
		if (!(state & (1 << index))) {
			dfs(index, state, distance + map[loc][index], num_locations);
		}
	}

	return EXIT_SUCCESS;
}
