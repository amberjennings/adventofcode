#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[32];
	char *token;
	int nums[16];
	int index, j, count, max, can_save, safe = 0;
	int temp[16], temp_index;
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

		if (valid && (increasing || decreasing)) {
			++safe;
			continue;
		}

		max = index;
		can_save = 0;

		for (index = 0; index < max; ++index) {
			temp_index = 0;
			for (j = 0; j < max; ++j) {
				if (j != index)
					temp[temp_index++] = nums[j];
			}

			valid = 1;
			increasing = 1;
			decreasing = 1;

			for (count = 0; count < temp_index - 1; ++count) {
				diff = abs(temp[count + 1] - temp[count]);

				if (diff < 1 || diff > 3) {
					valid = 0;
					break;
				}

				if (temp[count + 1] > temp[count]) decreasing = 0;
				else if (temp[count + 1] < temp[count]) increasing = 0;
			}

			if (valid && (increasing || decreasing)) {
				can_save = 1;
				break;
			}
		}

		if (can_save) ++safe;
	}

	fclose(file);
	fprintf(stdout, "%d\n", safe);
	return EXIT_SUCCESS;
}
