#include "../libft.h"
#include "stdio.h"

void testIsAlpha();
void testIsAscii();
void testToUpper();
void testToLower();
void testStrChr();
void testStrrChr();

int main()
{
	testStrrChr();
	return (0);
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

	for (ch = -5; ch <= 128; ch++) {
		printf("%d    ", ch);
		if (ft_isascii(ch))
			printf("The character is %c\n", ch);
		else
			printf("Cannot be represented by an ASCII character\n");
	}
}
