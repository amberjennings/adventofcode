CC := gcc
STD := -std=c89
DEBUG := -g3 -O0
WERROR := -Werror -Wshadow -Wunreachable-code -Wredundant-decls \
		 -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes \
		 -Wdeclaration-after-statement -Wextra -Wall -Wpedantic
CFLAGS := $(WERROR) $(DEBUG) $(STD)
LDFLAGS :=

part1 = uno
part2 = dos

part1_s = uno.c
part2_s = dos.c

.PHONY: 1 2 clean cls run

all: 1 2

run: $(part1) $(part2)
	@printf "Part 1: `./$(part1)`\n"
	@printf "Part 2: `./$(part2)`\n"

1: $(part1_s)
	$(CC) $(CFLAGS) $< -o $(part$@) $(LDFLAGS)

2: $(part2_s)
	$(CC) $(CFLAGS) $< -o $(part$@) $(LDFLAGS)

clean cls:
	rm -f $(part1) $(part2)
