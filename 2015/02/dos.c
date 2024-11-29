#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[20];
	int l, w, h, index, smallest, shortest;
	int dimensions[3];
	long ribbon = 0;

	while (fgets(input, sizeof(input), file)) {
		if (sscanf(input, "%dx%dx%d", &l, &w, &h) == 3) {
			dimensions[0] = l * w;
			dimensions[1] = w * h;
			dimensions[2] = h * l;
			smallest = dimensions[0];
			for (index = 1; index < 3; ++index) {
				if (dimensions[index] < smallest) {
					smallest = dimensions[index];
				}
			}
			shortest = 2 * (l + w);
			if (2 * (w + h) < shortest) shortest = 2 * (w + h);
			if (2 * (h + l) < shortest) shortest = 2 * (h + l);

			ribbon += shortest + l * w * h;
		}
	}

	fprintf(stdout, "%ld\n", ribbon);
	fclose(file);
	return EXIT_SUCCESS;
}
