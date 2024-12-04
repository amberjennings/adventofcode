#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[24576];
	char *pattern = "mul\\(([0-9]+),([0-9]+)\\)";
	char *line;
	int l, r, sum = 0;
	regex_t re;
	regmatch_t pmatch[3];

	regcomp(&re, pattern, REG_EXTENDED);

	fread(input, 1, sizeof(input), file);
	line = input;
	while (regexec(&re, line, 3, pmatch, 0) == 0) {
		l = atoi(line + pmatch[1].rm_so);
		r = atoi(line + pmatch[2].rm_so);
		sum += l * r;
		line += pmatch[0].rm_eo;
	}

	fprintf(stdout, "%d\n", sum);
	fclose(file);
	regfree(&re);
	return EXIT_SUCCESS;
}
