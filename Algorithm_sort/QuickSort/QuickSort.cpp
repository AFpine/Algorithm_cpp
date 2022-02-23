#include <iostream>

static int count = 0;

int Partition(int* arr, int p, int r)
{
	int x;
	int temp;
	int i = p - 1;
	x = arr[r];
	for (int j = p; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{ 
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			count++;
		}
	}
	arr[r]= arr[i + 1];
	arr[i + 1] = x;
	count++;
	return i + 1;
}

void QuickSort(int *arr, int p, int r)
{
	int q;
	if (p < r)
	{
		q = Partition(arr, p, r);
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q+1, r);
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
	QuickSort(array, 0, n - 1);
	std::cout << count << std::endl;
	delete[] array;

}