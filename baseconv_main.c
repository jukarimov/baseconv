#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define putd(c) (printf("[%d]\n", c))
void float_to_bin(char *ft, char *out);
long int base_to_dec(char *str, int base);
void base_to_base(char *str, int ibase, int obase, char *out);
void dec_to_base(long int dec, int base, char *out);

int main()
{
	/*
	char str[80];
	char *g;
	int n = strtol("1010,101", &g, 2);
	putd(n);
	*/
	char str[80];
	base_to_base("273", 10, 16, str);
	puts(str);

	char *g;
	int n = strtol("111", &g, 16);
	putd(n);

	return 0;
}

