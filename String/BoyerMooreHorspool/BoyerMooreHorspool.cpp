#include <iostream>
#include <string>

void computeJump(std::string& P, int jump[])
{
	int j = P.size();
	for (int i = 0; i < 26; i++)
	{
		jump[i] = j;
	}
	for (int i=0;i<P.size()-1;i++)
	{
		j--;
		jump[P[i] - 97] = j;
	}
	jump[P[P.size() - 1] - 97] = P.size();
}

void BoyerMooreHorspool(std::string& A, std::string& P)
{
	int jump[26] = {0};
	int j, k;
	int n = A.size();
	int m = P.size();
	int count = 0;
	int pcount = 0;
	int i = 0;
	computeJump(P, jump);
	while (i <= n - m)
	{
		j = m; k = i + m - 1;
		while (j > 0 && P[j-1] == A[k])
		{
			count++;
			j--;
			k--;
		}
		if (j == 0)
		{
			pcount++;
		}
		i = i + jump[A[i + m - 1]-97];
	}
	std::cout << count << " " << pcount;
}

int main()
{
	std::string A, P;
	std::cin >> A >> P;
	BoyerMooreHorspool(A, P);
}