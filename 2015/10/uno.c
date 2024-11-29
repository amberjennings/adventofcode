#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITERATIONS 40
#define INIT_BUF 1024

char *look_say(char *);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char *value = malloc(INIT_BUF);
	int count;

	fscanf(file, "%s", value);

	for (count = 0; count < ITERATIONS; ++count) {
		value = look_say(value);
	}

	fprintf(stdout, "%lu\n", (long unsigned) strlen(value));
	fclose(file);
	free(value);
	return EXIT_SUCCESS;
}

char *look_say(char *input) {
	char curr;
	char *result = malloc(max);
	int max = (int) strlen(input) * 2 + 1;
	int len = (int) strlen(input);
	int index, count;
	int insert = 0;

	for (index = 0; index < len;) {
		curr = input[index];
		count = 1;

		while (index + count < len && input[index + count] == curr) ++count;

		insert += sprintf(result + insert, "%d", count);
		result[insert++] = curr;

		index += count;
	}

	result[insert] = '\0';

	return result;
}
