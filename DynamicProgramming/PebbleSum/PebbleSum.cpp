#include <iostream>
#include <vector>
 
int way(int** w,int i, int p)
{
	if (p == 1)
	{
		return w[0][i];
	}
	if (p == 2)
	{
		return w[1][i];
	}
	if (p == 3)
	{
		return w[2][i];
	}
	if (p == 4)
	{
		return w[0][i]+w[2][i];
	}
}

int max(int x, int y)
{
	int max = x;
	if (y > max)
	{
		max = y;
	}
	return max;
}

int max(int x, int y, int z)
{
	int max = x;
	if (y > max)
	{
		max = y;
	}
	if (max < z)
	{
		max = z;
	}
	return max;
}

int max(int x, int y, int z, int w)
{
	int max = x;
	if (y > max)
	{
		max = y;
	}
	if (max < z)
	{
		max = z;
	}
	if (max < w)
	{
		max = w;
	}
	return max;
}

int main()
{
	int p;
	int n, val;
	std::cin >> n;
	int *w[3];
	for (int i = 0; i < 3; i++)
	{
		w[i] = new int[n];
	}
	int* peb[4];
	for (int i = 0; i < 4; i++)
	{
		peb[i] = new int[n];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> val;
			w[i][j] = val;
		}
	}
	peb[0][0] = way(w, 0, 1);
	peb[1][0] = way(w, 0, 2);
	peb[2][0] = way(w, 0, 3);
	peb[3][0] = way(w, 0, 4);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				peb[j][i] = max(peb[1][i-1], peb[2][i-1]) + way(w, i, 1);
			}
			if (j == 1)
			{
				peb[j][i] = max(peb[0][i-1], peb[2][i-1],peb[3][i-1]) + way(w, i, 2);
			}
			if (j == 2)
			{
				peb[j][i] = max(peb[0][i-1], peb[1][i-1]) + way(w, i, 3);

			}
			if (j == 3)
			{
				peb[j][i] = peb[1][i-1] + way(w, i, 4);
			}
		}
	}
	std::cout << max(peb[0][n - 1], peb[1][n - 1], peb[2][n - 1], peb[3][n - 1]);
}