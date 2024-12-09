#define OPENSSL_API_COMPAT 0x10100000L

#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[16];
	char password[8] = {0};
	char *prefix = malloc(strlen(input) + 64);
	unsigned char *hash = malloc(16);
	unsigned long num = 0;
	int counter = 0;

	fgets(input, sizeof(input), file);
	input[strcspn(input, "\n")] = 0;

	*prefix = 0;
	sprintf(prefix, "%s", input);

	while (counter < 8) {
		++num;
		sprintf(prefix + strlen(input), "%lu", num);
		MD5((const unsigned char *) prefix, strlen(prefix), hash);
		if (!hash[0] && !hash[1] && hash[2] < 0x10) {
			password[counter] = (hash[2] < 10) ? (hash[2] + '0') : (hash[2] - 10 + 'a');
			++counter;
		}
	}
	password[counter] = '\0';

	fprintf(stdout, "%s\n", password);
	free(prefix);
	free(hash);
	fclose(file);
	return EXIT_SUCCESS;
}
