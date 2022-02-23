#include <iostream>


static int count=0;

int theLargest(int* arr, int k)
{
	int largest = 0;
	for (int i = 1; i <= k; i++)
	{
		if (arr[i] > arr[largest])
		{
			count++;
			largest = i;
		}
	}
	return largest;
}

void selectionSort(int *arr, int n)
{
	int largeindex;
	int temp;
	for (int k = n - 1; k >= 1; k--)
	{
		largeindex = theLargest(arr, k);
		temp = arr[k];
		arr[k] = arr[largeindex];
		arr[largeindex] = temp;
	}
	std::cout << count << std::endl;
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
 	selectionSort(array, n);
	delete [] array;
}