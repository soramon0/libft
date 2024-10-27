#include "../libft.h"
#include "stdio.h"

void testIsAlpha();
void testIsAscii();

int main()
{
	testIsAlpha();
	return (0);
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
