#include <iostream>
#include <vector>
#include <cmath>

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
		}
	}
	A[r] = A[i + 1];
	A[i + 1] = x;
	return i + 1;
}

int Select(std::vector<int>& a, int p, int r, int i)		//No problem
{
	int q, k;
	if (p == r)
	{
		return a[p];
	}
	q = Partition(a, p, r);
	k = q - p + 1;
	if (i < k)
	{
		return Select(a, p, q - 1, i);
	}
	else if (i > k)
	{
		return Select(a, q + 1, r, i - k);
	}
	else
	{
		return a[q];
	}
}

int PartitionByMedian(std::vector<int>& A, int p, int r, int M)
{
	int i,temp;
	for (int k = p; k <= r; k++)
	{
		if (A[k] == M)
		{
			i = k;
		}
	}
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;
	return Partition(A, p, r);
}

int LinearSelect(std::vector<int>& A, int p, int r, int i)
{
	int k;						//order of M
	int n = r - p + 1;			//n = length of A
	int num_groups;				//length of B
	double ng;					//double num_of_groups
	int p1 = p;
	int r1 = p+4;
	int m = n % 5;				//number of elements of last group
	int q;
	int M;						//Median
	if (n <= 5)
	{
		return Select(A, p, r, i);
	}
	ng = ceil(double(n) / 5);
 	num_groups = int(ng);
	std::vector<int> B(num_groups);
	for (int k = 0; k < num_groups; k++)
	{
		if (r1 > r)
		{
			r1 -= 5;
			if (m == 1)
			{
				B[k] = Select(A, p1, r1+1, m/2+1);
			}
			else if(m==2)
			{
				B[k] = Select(A, p1, r1+2, m/2);
			}
			else if (m == 3)
			{
				B[k] = Select(A, p1, r1+3, m / 2 + 1);
			}
			else if (m == 4)
			{
				B[k] = Select(A, p1, r1+4, m/2);
			}
		}
		else
		{
			B[k] = Select(A, p1, r1, 3);
		}
		p1 += 5;
		r1 += 5;
	}
	M = LinearSelect(B, 0, num_groups-1, int(ceil(ng/2)));
	std::cout << M << std::endl;
	q = PartitionByMedian(A, p, r, M);
	k = q - p + 1;
	if (i < k)
	{
		return LinearSelect(A, p, q - 1, i);
	}
	else if (i > k)
	{
		return LinearSelect(A, q + 1, r, i - k);
	}
	else
	{
		return A[q];
	}
}

int main()
{
	int n, i;
	std::cin >> n >> i;
	std::vector<int> A(n);
	for (int k = 0; k < n; k++)
	{
		std::cin >> A[k];
	}
	LinearSelect(A, 0, n - 1, i);
}