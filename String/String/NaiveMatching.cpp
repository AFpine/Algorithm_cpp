#include <iostream>
#include <string>

int main()
{
	int n, m;
	std::string A, P;
	int count = 0;
	int pcount = 0;
	int flag = 0;
	std::cin >> A >> P;
	n = A.length();
	m = P.length();
	for (int i = 0; i < n - m + 1; i++)
	{
		flag = 0;
		for (int j = i; j < i+m; j++)
		{
			count++;
			if (A[j] != P[j-i])
			{
				flag++;
				break;
			}
		}
		if (flag == 0)
		{
			pcount++;
		}
	}
	std::cout << count << " " << pcount;
}