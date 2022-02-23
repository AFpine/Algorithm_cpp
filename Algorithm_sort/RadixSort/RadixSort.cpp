#include <iostream>
#include <vector>
#include <queue>


int digit(int A, int t)
{
	int div = 1;
	for (int i = 1; i < t; i++)
	{
		div *= 10;
	}
	return (A / div)%10;
}

void RadixSort(std::vector<int>&A, int n, int k)
{
	int d;
	int p;
	std::queue<int> q[10];
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d = digit(A[j], i);
			q[d].push(A[j]);
		}
		p = 0;
		for (int j = 0; j < 10; j++)
		{
			while (!q[j].empty())
			{
				A[p] = q[j].front();
				q[j].pop();
				p++;
			}
		}
	}
}

int main()
{
	int n;
	int t;
	std::cin >> n>>t;
	std::vector<int> A(n,0);
	for (int i = 0; i < n; i++)
	{
		std::cin >> A[i];
	}
	RadixSort(A, n, t);
	for (int i = 0; i < n; i++)
	{
		std::cout << A[i] << " ";
	}
}


//void CountingSort(std::vector<int>& a, std::vector<int>& b, int n)		//way better algorithm!
//{
//	std::vector<int> c(10, 0);
//	for (int i = 0; i < n; i++)
//	{
//		c[a[i]]++;
//	}
//	for (int i = 1; i < 10; i++)
//	{
//		c[i] += c[i - 1];
//	}
//	for (int i = n - 1; i >= 0; i--)
//	{
//		b[c[a[i]] - 1] = a[i];
//		c[a[i]]--;
//	}
//}