#include <iostream>
#include <string>
#include <cmath>

void basicRabinKarp(std::string& A, std::string& P, int d)
{
	int count = 0;
	int n = A.size();
	int m = P.size();
	int p = 0;
	int a[1000] = { 0 };
	for (int i = 0; i < m; i++)
	{
		p = d * p + (P[i]-97);
		a[0] = d * a[0] + (A[i]-97);
	}
	for (int i = 0; i < n - m + 1; i++)
	{
		if (i == 0)
		{
			std::cout << a[0] << " ";
		}
		else
		{
			std::cout << a[i - 1] << " ";
		}
		if (i != 0)
		{
			a[i] = d * (a[i-1] - (pow(d, m - 1) * (A[i-1] - 97))) + (A[i + m - 1] - 97);
		}
		if (p == a[i])
		{
			count++;
		}
	}
	std::cout << count;
}

int main()
{
	std::string A, P;
	std::cin >> A >> P;
	basicRabinKarp(A, P, 10);
}