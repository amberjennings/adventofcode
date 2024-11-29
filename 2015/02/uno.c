#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[20];
	int l, w, h, area, smallest;
	long total = 0;

	while (fgets(input, sizeof(input), file)) {
		if (sscanf(input, "%dx%dx%d", &l, &w, &h) == 3) {
			area = 2 * (l * w + w * h + h * l);
			smallest = l * w;
			if (w * h < smallest) smallest = w * h;
			if (h * l < smallest) smallest = h * l;

			total += (area + smallest);
		}
	}

	fprintf(stdout, "%ld\n", total);
	fclose(file);
	return EXIT_SUCCESS;
}
