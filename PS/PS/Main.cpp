#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void binarySearch(vector<long long>&tree, long long p, long long r, long long M, long long &h, long long &H)
{
	int sum = 0;
	int q = (p + r) / 2;
	if (p == r)
	{
		for (int i = 0; i < tree.size(); i++)
		{
			if (q < tree[i])
			{
				sum += tree[i] - q;
			}
		}
		if (sum >= M)
		{
			if (h >= sum)
			{
				h = sum;
				H = q;
			}
		}
	}
	else if(p<r)
	{
		for (int i = 0; i < tree.size(); i++)
		{
			if (q < tree[i])
			{
				sum += tree[i] - q;
			}
		}
		if (sum >= M)
		{
			if (h >= sum)
			{
				h = sum;
				H = q;
			}
			binarySearch(tree, q+1, r, M, h, H);
		}
		else
		{
			binarySearch(tree, p, q-1, M, h, H);
		}
	}
}

int main()
{
	long long H = 0;
	int N;
	long long M, max=0;
	long long sum=0, h;
	cin >> N >> M;
	vector<long long>tree(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		sum += tree[i];
		if (tree[i] > max)
		{
			max = tree[i];
		}
	}
	h = sum;
	sort(tree.begin(), tree.end());
	binarySearch(tree, 0, max, M, h, H);
	
	cout << H;
	return 0;
}