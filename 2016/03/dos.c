#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	int tri[3][3];
	int count = 0;
	int index;

	while (fscanf(file, "%d %d %d", &tri[0][0], &tri[0][1], &tri[0][2]) == 3 &&
		   fscanf(file, "%d %d %d", &tri[1][0], &tri[1][1], &tri[1][2]) == 3 &&
		   fscanf(file, "%d %d %d", &tri[2][0], &tri[2][1], &tri[2][2]) == 3) {
		for (index = 0; index < 3; ++index) {
			if (tri[0][index] + tri[1][index] > tri[2][index] &&
				tri[0][index] + tri[2][index] > tri[1][index] &&
				tri[1][index] + tri[2][index] > tri[0][index]) {
				++count;
			}
		}
	}
	fprintf(stdout, "%d\n", count);
	fclose(file);
	return EXIT_SUCCESS;
}
