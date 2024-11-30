#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char *token;
	char input[1024];
	int curr[2] = {0, 0};
	int visited[512][2];
	int index_p, index_v;
	int steps, step_count, found;
	int direction = 0;

	fgets(input, sizeof(input), file);
	token = strtok(input, ", ");

	while (token != NULL) {
		if (token[0] == 'R') {
			direction = (direction + 1) % 4;
		} else if (token[0] == 'L') {
			direction = (direction + 3) % 4;
		}

		sscanf(token + 1, "%d", &steps);

		for (step_count = 0; step_count < steps; ++step_count) {
			if (direction == 0)
				curr[1] += 1;
			else if (direction == 1)
				curr[0] += 1;
			else if (direction == 2)
				curr[1] -= 1;
			else if (direction == 3)
				curr[0] -= 1;

			found = 0;

			for (index_v = 0; index_v < index_p; ++index_v) {
				if (visited[index_v][0] == curr[0] &&
					visited[index_v][1] == curr[1]) {
					found = 1;
					break;
				}
			}

			if (found) {
				fprintf(stdout, "%d\n", abs(curr[0])
						+ abs(curr[1]));
				fclose(file);
				return EXIT_SUCCESS;
			}

			visited[index_p][0] = curr[0];
			visited[index_p][1] = curr[1];
			++index_p;
		}
		token = strtok(NULL, ", ");
	}
	fclose(file);
	return EXIT_FAILURE;
}
