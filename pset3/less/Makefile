#
# Makefile
# CS50
#
# clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm -L /usr/local/lib -I /usr/local/include
# clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c -L /usr/local/lib -I /usr/local/include

all: find generate

find: find.c helpers.c helpers.h
	clang -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm -L /usr/local/lib -I /usr/local/include

generate: generate.c
	clang -O0 -std=c11 -Wall -Werror -o generate generate.c -L /usr/local/lib -I /usr/local/include

clean:
	rm -f *.o a.out core find generate
