#include <iostream>
#include <vector>


//void CountingSort(int* arrA, int* arrB, int* arrC, int k, int n, int min)
//{
//	for (int i = 0; i < k; i++)
//	{
//		arrB[i] = 0;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		arrB[arrA[i] - min]++;
//	}
//	for (int i = 1; i < k; i++)
//	{
//		arrB[i] += arrB[i - 1];
//	}
//	for (int i = n - 1; i >= 0; i--)
//	{
//		arrC[arrB[arrA[i] - min] - 1] = arrA[i];
//		arrB[arrA[i] - min]--;
//	}
//
//}
//
int MaxVal(std::vector<int>& a,int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int MinVal(std::vector<int>& a, int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}


void CountingSort(std::vector<int>& a,std::vector<int>& b, int n,int k,int min)		//way better algorithm!
{
	std::vector<int> c(k);
	for (int i = 0; i < n; i++)
	{
		c[a[i]-min]++;
	}
	for (int i = 1; i < k; i++)
	{
		c[i] += c[i - 1];
	}
	for (int i = 0; i < k; i++)
	{
		std::cout << c[i] << " ";
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[c[a[i]-min]-1] = a[i];
		c[a[i]-min]--;
	}
}

int main()
{
	int max, min;
	int n,k;
	std::cin >> n;
	std::vector<int> A(n);
	std::vector<int> B(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> A[i];
	}
	max = MaxVal(A,n);
	min = MinVal(A,n);
	k = max - min + 1;
	CountingSort(A,B,n,k,min);
}