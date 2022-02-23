#include <iostream>
#include <vector>

static int M = 0;
static int count = 0;

int h_i(int i, int x)
{
	return (x + i) % M;
}

int main()
{
	int N;
	int prime;
	int flag = 0;
	int index;
	int x;
	int k;
	std::cin >> N;
	prime = N * 2;
	while (1)
	{
		flag = 0;
		for (int i = 2; i < prime; i++)
		{
			if (prime % i == 0)
			{
				flag++;
				break;
			}
		}
		if (flag == 0)
		{
			M = prime;
			break;
		}
		prime++;
	}
	std::vector<int> H(M, 0);
	for (int i = 0; i < N; i++)
	{
		k = 0;
		std::cin >> x;
		index = h_i(k, x);
		while (H[index] != 0)
		{
			k++;
			index = h_i(k, x);
			count++;
		}
		H[index] = x;
	}
	std::cout << count;
}