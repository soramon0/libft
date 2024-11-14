#include "../libft.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

void testIsAlpha();
void testIsAscii();
void testToUpper();
void testToLower();
void testStrChr();
void testStrrChr();
void testStrnCmp();
void testStrnStr();
void testAtoi();
void testMemset();
void testMemchr();
void testMemcpy();
void testMemmove();
void testMemcmp();
void testBzero();
void testStrdup();
void testCalloc();
void testStrlcpy();
void testStrlcat();
void testSubstr();
void testStrjoin();
void testStrtrim();
void testSplit();

int main()
{
	testSplit();
	return (0);
}

void testSplit()
{
	char *str = " Hello   Wrold ";
	char sep  = ' ';
	char **r = ft_split(str, sep);
	printf("%p\n", r);
	while (r != NULL && *r != NULL)
	{
		printf("%s\n", *r);
		r++;
	}
}

void testStrtrim()
{
	char *s1= "Hello    World";
	char *set = " ";
	char *ret = ft_strtrim(s1, set);
	printf("got '%s'\n", ret);
}

void testStrjoin()
{
	char *s1= "Hello";
	char *s2 = "World";
	char *ret = ft_strjoin(s1, s2);
	printf("got '%s'\n", ret);
}

void testSubstr()
{
	char *str = "Hello World";
	char *ret = ft_substr(str, 6, 5);
	printf("got '%s'\n", ret);
}

void testStrlcat()
{
	char dst1[12] = {'H', 'e', 'l', 'l', 'o'};
	const char *src1 = " World";
	size_t dst1len = ft_strlen(dst1);
	size_t r1 = ft_strlcat(dst1, src1, sizeof(dst1) / 2);
	printf("src: %s\n", src1);
	printf("dst: %s\n", dst1);
	printf("src length: %zu\n", ft_strlen(src1));
	printf("dst length: %zu\n", dst1len);
	printf("Returned length: %zu\n", r1);

	printf("------------------\n");

	char dst2[12] = {'H', 'e', 'l', 'l', 'o'};
	size_t dst2len = ft_strlen(dst2);
	const char *src2 = " World";
	size_t r2 = ft_strlcat(dst2, src2, sizeof(dst2) / 2);
	printf("src: %s\n", src2);
	printf("dst: %s\n", dst2);
	printf("src length: %zu\n", ft_strlen(src2));
	printf("dst length: %zu\n", dst2len);
	printf("Returned length: %zu\n", r2);
}

void testStrlcpy()
{
	char dst1[6];
	const char *src1 = "Hello";
	size_t r1 = ft_strlcpy(dst1, src1, sizeof(dst1));
	printf("src: %s\n", src1);
	printf("dst: %s\n", dst1);
	printf("Expected length: %zu\n", ft_strlen(src1));
	printf("Returned length: %zu\n", r1);
}

typedef struct {
	int value;
} Calloc_test;

void testCalloc()
{
	Calloc_test *c = ft_calloc(sizeof(Calloc_test), sizeof(Calloc_test) * 10);
	size_t i = 0;
	while (i < 10)
	{
		printf("Struct[%zu].value = %d\n", i, c->value);
		i++;
	}
}

void testStrdup()
{
	char *src = "Hello World";
	char *dup = ft_strdup(src);
	printf("src = '%s'\n", src);
	printf("dup = '%s'\n", dup);
}

void testBzero()
{
	int ft_n[5];
	int n[5];
	int c = -1;

	ft_memset(ft_n, c, sizeof(ft_n));
	memset(n, c, sizeof(n));

	for (size_t i = 0; i < 5; i++) {
		printf("%d | %d\n", ft_n[i], n[i]);
	}

	bzero(n, sizeof(n));
	bzero(ft_n, sizeof(ft_n));

	for (size_t i = 0; i < 5; i++) {
		printf("%d | %d\n", ft_n[i], n[i]);
	}
}

void testMemmove()
{
	char src1[] = "Hello World";
	int dst1[11];
	char *r1 = memmove(dst1, src1, sizeof(src1));
	printf("src1 = %s\n", src1);
	printf("ft_memmove = %s\n", r1);

	char src2[] = "Hello World";
	int dst2[11];
	char *r2 = memmove(dst2, src2, sizeof(src2));
	printf("src2 = %s\n", src2);
	printf("memmove = %s\n", r2);
}

void testMemcmp()
{
	int arr1[] = {1, 2};
	int arr2[] = {1, 1};
	int r1 = ft_memcmp(arr1, arr2, sizeof(int) * 2);
	int r2 = memcmp(arr1, arr2, sizeof(int) * 2);
	printf("array ft_memcmp = %d\n", r1);
	printf("array memcmp = %d\n", r2);

	int a = -1;
	short int b = 1;
	r1 = ft_memcmp(&a, &b, sizeof(short int));
	r2 = memcmp(&a, &b, sizeof(short int));
	printf("scalar ft_memcmp = %d\n", r1);
	printf("scalar memcmp = %d\n", r2);
}

void testMemcpy()
{
	int src[] = {1, 2};
	int dst1[2] = {0};
	int dst2[2] = {0};
	int len = sizeof(src) / sizeof(src[0]);

	int *r1 = ft_memcpy(dst1, src, sizeof(src));
	int *r2 = memcpy(dst2, src, sizeof(src));

	int i = 0;
	while (i < len){
		printf("ft_memcpy = %d\n", r1[i]);
		printf("memcpy = %d\n", r2[i]);
		i++;
	}
}

void testMemchr()
{
	int arr1[] = {1, 2};
	int c = 1;

	int *r1 = ft_memchr(arr1, c, sizeof(int));
	int *r2 = memchr(arr1, c, sizeof(int));

	if (r1) 
		printf("ft_memchr = %d\n", *r1);
	else
		printf("ft_memchr = %p\n", r1);

	if (r2)
		printf("memchr = %d\n", *r2);
	else
		printf("memchr = %p\n", r2);
}

void testMemset()
{
	int ft_n[5];
	int n[5];
	int c = 1;

	ft_memset(ft_n, c, sizeof(ft_n));
	memset(n, c, sizeof(n));

	for (size_t i = 0; i < 5; i++) {
		printf("%d | %d\n", ft_n[i], n[i]);
	}

	int a = 0;
	char *k = (char*) &a;
	memset(k, 199, 1);
	memset(k + 1, 250, 1);
	memset(k + 2, 255, 2);
	printf("%d\n", a);
}

void testAtoi() {
	char s[] = "-120aa";
	printf("%d\n", atoi(s));
	printf("%d\n", ft_atoi(s));
}

void testStrnStr()
{
	char haystack[] = "Foo Bar Baz";
	char needle[] = "Bar";
	size_t len = 5;
	char *result = ft_strnstr(haystack, needle, len);
	printf("haystack: '%s'\n", haystack);
	printf("needle: '%s'\n", needle);
	printf("len: %d\n", (int)len);
	printf("result: '%s'\n", result);
}

void testStrnCmp()
{
	char *s1 = "ABC";
	char s2[] = {'A', 'B', 0x81};
	int cases[] = {-1, 0, 1, 2, 3, 4, 5, 6};
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
