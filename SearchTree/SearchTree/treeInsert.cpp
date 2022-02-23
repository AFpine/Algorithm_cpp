#include <iostream>
#include <vector>

static int count = 0;

struct node
{
	int key;
	int right;
	int left;
};

int treeInsert(std::vector<node>& A,int t, int x)
{
	count++;
	int r;
	if (A[t].key == NULL)
	{
		A[t].key = x;
		A.push_back({NULL,NULL,NULL});
		A[t].left = A.size()-1;
		A.push_back({ NULL,NULL,NULL });
		A[t].right = A.size()-1;
		return t;
	}
	if (x < A[t].key)
	{
		r = A[t].left;
		r = treeInsert(A, r, x);
		return t;
	}
	else
	{
		r = A[t].right;
		r = treeInsert(A, r, x);
		return t;
	}
}


int main()
{
	int n,x;
	int t = 0;
	std::cin >> n;
	std::vector<int> T(n);
	std::vector<node> A(1);
	A[0] = { NULL,NULL,NULL };
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		T[i] = treeInsert(A, t, x);
	}
	std::cout << count << std::endl;
}