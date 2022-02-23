#include <stdio.h>

int main()
{
	int a, b;
	while (1)
	{

	scanf_s("%d %d", &a, &b);
	if ((a ^ b) == 0)
	{
		printf("same\n");
	}
	else
	{
		printf("diff\n");
	}
	}
}