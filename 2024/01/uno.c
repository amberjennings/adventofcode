#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	int l[1024], r[1024];
	int index = 0;
	int total = 0;

	while (fscanf(file, "%d %d", &l[index], &r[index]) == 2)
		++index;

	qsort(l, index, sizeof(int), compare);
	qsort(r, index, sizeof(int), compare);

	for (; index > 0; --index)
		total += abs(l[index - 1] - r[index - 1]);

	fprintf(stdout, "%d\n", total);
	fclose(file);
	return EXIT_SUCCESS;
}

int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}
