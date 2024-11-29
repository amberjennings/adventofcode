#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char pswd[9];
	int index, pairs, straight, valid;
	int gen = 0;

	fgets(pswd, sizeof(pswd), file);

	pswd[strcspn(pswd, "\n")] = '\0';

	while (gen < 2) {
		do {
			index = 7;
			valid = 1;
			pairs = 0;

			while (index >= 0) {
				if (pswd[index] == 'z') {
					pswd[index] = 'a';
					--index;
				} else {
					pswd[index]++;
					break;
				}
			}

			for (index = 0; pswd[index] != '\0'; ++index) {
				if (pswd[index] == 'i' || pswd[index] == 'o' || pswd[index] == 'l') {
					valid = 0;
					break;
				}
			}

			if (!valid) continue;

			straight = 0;
			for (index = 0; index < 6; ++index) {
				if (pswd[index] + 1 == pswd[index + 1] && pswd[index] + 2 == pswd[index + 2]) {
					straight = 1;
					break;
				}
			}

			if (!straight) continue;

			index = 0;
			while (pswd[index] != '\0') {
				if (pswd[index] == pswd[index + 1]) {
					++pairs;
					index += 2;
				} else ++index;
			}

		} while (pairs < 2);
		++gen;
	}

	fprintf(stdout, "%s\n", pswd);
	fclose(file);
	return EXIT_SUCCESS;
}
