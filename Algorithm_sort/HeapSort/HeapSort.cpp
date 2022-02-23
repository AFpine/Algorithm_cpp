#include <iostream>

static int count = 0;

void heapify(int* arr, int k, int n, int flag)
{
	int temp;
	int bigger;
	int left = 2*k+1;
	int right = 2*k + 2;
	if (right <= n)
	{
		if (arr[left] > arr[right])
		{
			bigger = left;
		}
		else
		{
			bigger = right;
		}
	}
	else if (left <= n)
	{
		bigger = left;
	}
	else
	{
		return;
	}
	if (arr[bigger] > arr[k])
	{
		temp = arr[bigger];
		arr[bigger] = arr[k];
		arr[k] = temp;
		if (flag)
		{
			count++;
		}
		heapify(arr, bigger, n,flag);
	}
}

void buildHeap(int* arr, int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		heapify(arr, i, n,0);
	}
}

void HeapSort(int* arr, int n)
{
	int temp;
	buildHeap(arr, n);
	for (int i = n; i >= 1; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, 0, i - 1,1);
	}
}

int main()
{
	int n;
	std::cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}
	HeapSort(array,n - 1);
	std::cout << count << std::endl;
	delete[] array;

}