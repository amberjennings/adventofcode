#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char letter;
	int frequency;
} freq;

int compare(const void *a, const void *b);

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char name[64], shifted[64], checksum[8], unverified[6] = {0};
	int alph[26], id, index;
	freq freqs[26];

	while (fscanf(file, "%[^0-9]%d[%[^]]%*[^\n]\n", name, &id, checksum) == 3) {
		memset(alph, 0, sizeof(alph));
		index = 0;
		while (name[index]) {
			if (isalpha(name[index]))
				++alph[name[index] - 'a'];
			++index;
		}

		for (index = 0; index < 26; ++index) {
			freqs[index].letter = 'a' + index;
			freqs[index].frequency = alph[index];
		}

		qsort(freqs, 26, sizeof(freq), compare);

		for (index = 0; index < 5 && freqs[index].frequency > 0; ++index)
			strncat(unverified, &freqs[index].letter, 1);

		if (strncmp(unverified, checksum, 5) == 0) {
			memset(shifted, 0, sizeof(shifted));
			strcpy(shifted, name);
			for (index = 0; shifted[index]; ++index) {
				if (islower(shifted[index]))
					shifted[index] = (shifted[index] - 'a' + id) % 26 + 'a';
			}

			if (strstr(shifted, "north"))
				break;
		}

		memset(unverified, 0, sizeof(unverified));
	}

	fprintf(stdout, "%d\n", id);
	fclose(file);
	return EXIT_SUCCESS;
}

int compare(const void *a, const void *b) {
	freq *freq_a = (freq *)a;
	freq *freq_b = (freq *)b;

	if (freq_b->frequency != freq_a->frequency)
		return freq_b->frequency - freq_a->frequency;

	return freq_a->letter - freq_b->letter;
}
