/* WIP */

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char input[4096];
	char *line;
	char *pattern = "mul\\(([0-9]+),([0-9]+)\\)";
	char *do_p = "do\\(\\)", *dont_p = "don't\\(\\)";
	int l, r, sum = 0;
	int mul = 1;
	regex_t re, do_r, dont_r;
	regmatch_t pmatch[3], dmatch[1];

	regcomp(&re, pattern, REG_EXTENDED);
	regcomp(&do_r, do_p, REG_EXTENDED);
	regcomp(&dont_r, dont_p, REG_EXTENDED);

	while (fgets(input, sizeof(input), file)) {
		line = input;
		while (regexec(&do_r, line, 1, dmatch, 0) == 0) {
			mul = 1;
			line += dmatch[0].rm_eo;
		}
		while (regexec(&dont_r, line, 1, dmatch, 0) == 0) {
			mul = 0;
			line += dmatch[0].rm_eo;
		}
		while (regexec(&re, line, 3, pmatch, 0) == 0) {
			if (mul) {
				l = atoi(line + pmatch[1].rm_so);
				r = atoi(line + pmatch[2].rm_so);
				sum += l * r;
			}
			line += pmatch[0].rm_eo;
		}
	}

	fprintf(stdout, "%d\n", sum);
	fclose(file);
	regfree(&re);
	regfree(&do_r);
	regfree(&dont_r);
	return EXIT_SUCCESS;
}
