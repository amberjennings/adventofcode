#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	int tri[3];
	int count = 0;

	while (fscanf(file, "%d %d %d", &tri[0], &tri[1], &tri[2]) == 3) {
		if (tri[0] + tri[1] > tri[2] &&
			tri[0] + tri[2] > tri[1] &&
			tri[1] + tri[2] > tri[0]) {
			++count;
		}
	}
	fprintf(stdout, "%d\n", count);
	fclose(file);
	return EXIT_SUCCESS;
}
