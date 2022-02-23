#include <iostream>
#include <vector>

int min(int x, int y)
{
	return (x < y) ? x : y;
}
int max(int x, int y)
{
	return (x > y) ? x : y;
}

int main()
{
	int n, m,val;
	std::cin >> n >> m;
	int** c = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		c[i] = new int[m + 1];
	}
	int** M = new int* [n];
	for (int i = 0; i < n ; i++)
	{
		M[i] = new int[m];
	}

	for (int i = 0; i < n + 1; i++)
	{
		c[i][0] = 0;
	}
	for (int i = 0; i < m + 1; i++)
	{
		c[0][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> val;
			M[i][j] = val;
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (i == 1 | j == 1)
			{
				c[i][j] = M[i - 1][j - 1] + max(c[i - 1][j], c[i][j - 1]);
			}
			else
			{
				c[i][j] = M[i - 1][j - 1] + min(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	std::cout << c[n][m];

	for (int i = 0; i < n + 1; i++)
	{
		delete[] c[i];
	}
	delete[] c;
	for (int i = 0; i < n; i++)
	{
		delete[] M[i];
	}
	delete[] M;
}