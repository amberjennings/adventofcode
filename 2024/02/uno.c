#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[32];
	char *token;
	int nums[16];
	int index, count;
	int safe = 0;
	int increasing, decreasing, valid, diff;

	while (fgets(input, sizeof(input), file)) {
		index = 0;
		token = strtok(input, " ");
		while (token) {
			nums[index] = atoi(token);
			++index;
			token = strtok(NULL, " ");
		}

		if (index < 2) continue;

		increasing = 1;
		decreasing = 1;
		valid = 1;

		for (count = 0; count < index - 1; ++count) {
			diff = abs(nums[count + 1] - nums[count]);

			if (diff < 1 || diff > 3) {
				valid = 0;
				break;
			}

			if (nums[count + 1] > nums[count]) decreasing = 0;
			else if (nums[count + 1] < nums[count]) increasing = 0;
		}

		if (valid && (increasing || decreasing)) ++safe;
	}

	fclose(file);
	fprintf(stdout, "%d\n", safe);
	return EXIT_SUCCESS;
}
