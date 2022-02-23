#include <iostream>

static int count = 0;

void InsertionSort(int* arr, int n)
{
	int std;
	for (int k = 1; k < n; k++)
	{
		std = arr[k];
		for (int i = k-1; i >= 0; i--)
		{
			if (arr[i] > std)
			{
				arr[i + 1] = arr[i];
				if (i == 0)
				{
					arr[0] = std;
					count++;
				}
				count++;
			}
			else
			{
				arr[i+1] = std;
				count++;
				break;
			}
		}
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
	InsertionSort(array, n);
	std::cout << count << std::endl;
	delete[] array;
}