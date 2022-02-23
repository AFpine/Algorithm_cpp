#include <iostream>

static int count = 0;

void Merge(int* arr, int* temp, int p, int q, int n);

void MergeSort(int* arr, int* temp, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		MergeSort(arr,temp, p, q);
		MergeSort(arr,temp, q + 1, r);
		Merge(arr,temp, p, q, r);
	}
}

void Merge(int* arr, int* temp, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 0;
	while (i <= q && j <= r)
	{
		if (arr[i] < arr[j])
		{
			temp[t++] = arr[i++];
			count++;
		}
		else
		{
			temp[t++] = arr[j++];
			count++;
		}
	}
	while (i <= q)
	{
		temp[t++] = arr[i++];
	}
	while (j <= r)
	{
		temp[t++] = arr[j++];
	}
	i = p;
	t = 0;
	while (i <= r)
	{
		arr[i++] = temp[t++];
	}
}

int main()
{
	int n;
	std::cin >> n;
	int* array = new int[n];
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}
	MergeSort(array,temp,0,n-1);
	std::cout << count << std::endl;
	delete[] array;
	delete[] temp;
}