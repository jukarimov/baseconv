#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#undef putc
#undef puts
#define puts(s) (printf("[%s]\n", s))
#define putx(x) (printf("[%x]\n", x))
#define putd(d) (printf("[%d]\n", d))
#define putld(ld) (printf("[%ld]\n", ld))
#define putf(f) (printf("[%f]\n", f))
#define putc(c) (printf("[%c]\n", c))
#define puterr(s) (fprintf(stderr, "[Error:%s]\n", s))

double pwr(int n, int base)
{
	double res = 1;
	while (base-- > 0)
		res *= n;

	return res;
}

void strcln(char *s)
{

	/*
	int j = strlen(s) - 1;
	for (; j >= 0; j--)
		s[j] = 0;
	*/
	while (*s--)
		*s = 0;

}


char *strrev(char *s, char *d)
{
	int i, j = strlen(s) - 1;
	for (i = 0; j >= 0; i++, j--)
		d[i] = s[j];

	d[i++] = 0;

	return d;
}

/*
  @n number to convert
  @str reversed number
*/
char *to_str(int n, char *str)
{
	int i = 0;
	while (n) {
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[i++] = 0;

	char *tmp = malloc(i + 1);
	strcpy(tmp, str);

	strrev(tmp, str);

	free(tmp);

	return str;
}

void dec_to_base(long int dec, int base, char *out)
{
	int i = 0, t;
	if (base == 2) {
		while (dec) {
			out[i++] = dec % base + '0';
			dec /= base;
		}
	}
	else if (base == 8) {
		while (dec) {
			out[i++] = dec % base + '0';
			dec /= base;
		}
	}
	else if (base == 16) {
		while (dec) {
			t = dec % base;
			dec /= base;
			if (t > 9 && t < 16)
				out[i] = (t % 10 + 65);
			else
				out[i] = t + '0';
				putc(out[i]);
			i++;
		}
	}
	else {
		puterr("Unknown base");
		strcpy(out, "err");
	}

	out[i++] = 0;

	/* reverse */
	char *tmp = malloc(i);
	strcpy(tmp, out);

	strrev(tmp, out);

	free(tmp);
}

long int base_to_dec(char *str, int base)
{

	int i, j, t, res;

	res = 0;
	j = strlen(str) - 1;
	for (i=0; j >= 0; i++, j--) {
		if (str[j] >= 'A' && str[j] <= 'F')
			t = str[j] % 65 + 10;
		else
			t = str[j] - '0';
		res += t * pwr(base, i);
	}

	return res;
}

void base_to_base(char *str, int ibase, int obase, char *out)
{
	int n = base_to_dec(str, ibase);
	if (obase == 10)
		to_str(n, out);
	else
		dec_to_base(n, obase, out);
}

void float_to_bin(char *ft, char *out)
{
	int dec = atoi(ft);
	
	dec_to_base(dec, 2, out);

	while (*ft++ != '.');

	puts(ft);
}

