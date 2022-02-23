#include <iostream>

using namespace std;

void BubbleSort(int* arr, int n)
{
	int count = 0;
	int temp;
	for (int k = n - 1; k >= 1; k--)
	{
		for (int i = 0; i < k; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				count+=1;
			}
		}
	}
	cout << count << endl;
}

int main()
{
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	BubbleSort(array, n);
}