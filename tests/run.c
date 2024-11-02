#include "../libft.h"
#include "stdio.h"
#include <string.h>

void testIsAlpha();
void testIsAscii();
void testToUpper();
void testToLower();
void testStrChr();
void testStrrChr();
void testStrnCmp();

int main()
{
	testStrnCmp();
	return (0);
}

void testStrnCmp()
{
	char *s1 = "ABC";
	char *s2 = "AB";
	unsigned int cases[] = {-1, 0, 1, 2, 3, 4, 5, 6};
	int size = 8;
	int i = 0;
	while (i < size)
	{
		int r1 = strncmp(s1, s2, cases[i]);
		int r2 = ft_strncmp(s1, s2, cases[i]);
		printf("strncmp(%s, %s, %d) = %d\n", s1, s2, cases[i], r1);
		printf("ft_strncmp(%s, %s, %d) = %d\n", s1, s2, cases[i], r2);
		if (i != size - 1)
			printf("--------------\n");
		i++;
	}
}

void testStrrChr()
{
	char *s = "karim is here!";
	int pos = 10;
	char *addr = &s[pos];
	printf("char '%c' at addr %p\n", *addr, addr);
	char *got = ft_strrchr(s, *addr);
	printf("%p - '%c'\n", got, *got);
}

void testStrChr()
{
	char *s = "karim is here!";
	int pos = 4;
	char *addr = &s[pos];
	printf("char '%x' at addr %p\n", *addr, addr);
	char *got = ft_strchr(s, *addr);
	printf("%p - '%x'\n", got, *got);
}

void testToLower()
{
	printf("%c\n", ft_tolower('D'));
}

void testToUpper()
{
	printf("%c\n", ft_toupper('d'));
}

void testIsAlpha()
{
	char c = 'k';
	int got = ft_isalpha(c);
	printf("Got: %d\n", got);
}

void testIsAscii()
{
	int ch;

	for (ch = -5; ch <= 128; ch++)
	{
		printf("%d    ", ch);
		if (ft_isascii(ch))
			printf("The character is %c\n", ch);
		else
			printf("Cannot be represented by an ASCII character\n");
	}
}
