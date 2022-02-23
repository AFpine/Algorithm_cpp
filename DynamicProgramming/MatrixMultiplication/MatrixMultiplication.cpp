#include <iostream>
#include <vector>

struct matrix
{
	int r;
	int c;
};

int min(int** w,std::vector<matrix>&p, int i, int j)
{
	int k;
	int min;
	int val;
	min = 100000000;
	for (k = i; k <= j - 1; k++)
	{
		val = w[i][k] + w[k + 1][j] + (p[i].r * p[k].c * p[j].c);
		if (val < min)
		{
			min = val;
		}
	}
	return min;
}

int main()
{
	int n;
	int r, c,j ;
	std::cin >> n;
	std::vector<matrix> m(n+1);
	int** w = new int* [n+1];
	for (int i = 0; i < n+1; i++)
	{
		w[i] = new int[n+1];
	}
	for (int i = 1; i < n+1; i++)
	{
		std::cin >> r >> c;
		m[i].r = r;
		m[i].c = c;
	}
	for (int i = 1; i <= n; i++)
	{
		w[i][i] = 0;
	}
	for (r = 1; r <= n - 1; r++)
	{
		for (int i = 1; i <= n - r; i++)
		{
			j = i + r;
			w[i][j] = min(w, m, i, j);
		}
	}
	std::cout << w[1][n];

	for (int i = 0; i < n + 1; i++)
	{
		delete[] w[i];
	}
	delete[] w;
}