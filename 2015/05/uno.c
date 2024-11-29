#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[20];
	char *bad[] = { "ab", "cd", "pq", "xy" };
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	char prev = '\0';
	int index, vowel, count, pair, is_bad;
	int good = 0;

	while (fgets(input, sizeof(input), file)) {
		input[strcspn(input, "\n")] = '\0';

		count = 0;
		pair = 0;
		is_bad = 0;

		for (index = 0; index < 4; ++index) {
			if (strstr(input, bad[index])) {
				is_bad = 1;
				break;
			}
		}
		if (is_bad) continue;

		prev = '\0';

		for (index = 0; input[index] != '\0'; ++index) {
			if (input[index] == prev) pair = 1;

			for (vowel = 0; vowel < 5; ++vowel)
				if (input[index] == vowels[vowel]) ++count;

			prev = input[index];
		}

		if (count >= 3 && pair == 1) ++good;
	}

	fprintf(stdout, "%d\n", good);
	fclose(file);
	return EXIT_SUCCESS;
}
