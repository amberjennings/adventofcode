#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	int l[1024], r[1024];
	int index = 0, index_r = 0;
	int max, count;
	int total = 0;

	while (fscanf(file, "%d %d", &l[index], &r[index]) == 2)
		++index;

	max = index;
	index = 0;

	qsort(l, max, sizeof(int), compare);
	qsort(r, max, sizeof(int), compare);

	while (index < max) {
		count = 0;
		while (index_r < max && r[index_r] < l[index]) ++index_r;
		while (index_r < max && r[index_r] == l[index]) {
			++count;
			++index_r;
		}

		total += l[index] * count;

		while (index < max - 1 && l[index] == l[index + 1]) ++index;
		++index;
	}

	fprintf(stdout, "%d\n", total);
	fclose(file);
	return EXIT_SUCCESS;
}

int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}
