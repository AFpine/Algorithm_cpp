#include <iostream>
#include <string>
#include <cmath>

int mod(long long x, long long y)
{
	return (((x % y) + y) % y);
}

void RabinKarp(std::string& A, std::string& P, int d, int q)
{
	int count = 0;
	int n = A.size();
	int m = P.size();
	long long p = 0;
	long long a[1000] = { 0 };
	for (int i = 0; i < m; i++)
	{
		p = mod((d * p + (long long)(P[i] - 97)), q);
		a[0] = mod((d * a[0] + (long long)(A[i] - 97)), q);
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
			a[i] = mod((d * mod((a[i - 1] - (pow(d, m - 1) * (long long)(A[i - 1] - 97))),q) + ((long long)A[i + m - 1] - 97)),q);
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
	RabinKarp(A, P, 26, 113);
}