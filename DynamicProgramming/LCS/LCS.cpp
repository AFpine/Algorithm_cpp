#include <iostream>

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int main()
{
	int m, n;
	int** c;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	m = s1.length();
	n = s2.length();
	c = new int* [m+1];
	for (int i = 0; i < m+1 ; i++)
	{
		c[i] = new int[n+1];
	}
	for (int i = 0; i <= m; i++)
	{
		c[i][0] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		c[0][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i-1]==s2[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	std::cout << c[m][n];
}