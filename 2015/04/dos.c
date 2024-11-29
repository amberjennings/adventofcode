#define OPENSSL_API_COMPAT 0x10100000L

#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[20];
	char *prefix = malloc(strlen(input) + 50);
	unsigned char *sum = malloc(16);
	unsigned long num = 0;

	fgets(input, sizeof(input), file);
	input[strcspn(input, "\n")] = 0;

	*prefix = 0;
	sprintf(prefix, "%s", input);

	while(1) {
		++num;
		sprintf(prefix + strlen(input), "%lu", num);
		MD5((const unsigned char *) prefix, strlen(prefix), sum);

		if(!sum[0] && !sum[1] && !sum[2] && sum[2] < 0x10) {
			fprintf(stdout, "%lu\n", num);
			fclose(file);
			return EXIT_SUCCESS;
		}
	}
}
