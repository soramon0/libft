#include "../libft.h"
#include "stdio.h"

typedef struct TestCase
{
	const char* name;
	const char* value;
	int want;
} TestCase;

TestCase *initTestCase(char *name, char *value, int want)
{
	static TestCase testCase;
	testCase.name = name;
	testCase.value = value;
	testCase.want = want;

	return &testCase;
}

int main()
{
	int SIZE = 3;
	TestCase *testCases[SIZE];
	int i;
	int j;
	int got;

	testCases[0] = initTestCase("Cantains letter", "k", 1);
	testCases[1] = initTestCase("Contains number", "1", 0);
	testCases[2] = initTestCase("Contains special character", "+", 0);
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (testCases[i]->value[j])
		{
			got = ft_isalpha(testCases[i]->value[j]);
			if (got != testCases[i]->want)
			{
				printf("%s: value = '%s' got = %d; want %d\n", testCases[i]->name, testCases[i]->value, got, testCases[i]->want);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
