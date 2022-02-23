#include <iostream>
#include <vector>

static int count = 0;

int Partition(std::vector<int>& A, int p, int r)
{
	int x;
	int temp;
	int i = p - 1;
	x = A[r];
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			count++;
		}
	}
	A[r] = A[i + 1];
	A[i + 1] = x;
	count++;
	return i + 1;
}

int Select(std::vector<int>& A, int p, int r, int i)
{
	int q,k;
	if (p == r)
	{
		return A[p];
	}
	q = Partition(A, p, r);
	k = q - p + 1;
	if (i < k)
	{
		return Select(A, p, q - 1, i);
	}
	else if (i == k)
	{
		return A[q];
	}
	else
	{
		return Select(A, q + 1, r, i - k);
	}
}

int main()
{
	int n, i;
	int result;
	std::cin >> n >> i;
	std::vector<int> A(n);
	for (int k = 0; k < n; k++)
	{
		std::cin>>A[k];
	}
	result = Select(A, 0, n - 1,i);
	std::cout << count << std::endl;
	std::cout << result << std::endl;
}