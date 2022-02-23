#include <iostream>
#include <vector>


struct node
{
	int key;
	int right;
	int left;
};

int treeInsert(std::vector<node>& A, int t, int x)
{
	int r;
	if (A[t].key == NULL)
	{
		A[t].key = x;
		A.push_back({ NULL,-1,-1 });
		A[t].left = A.size() - 1;
		A.push_back({ NULL,-1,-1 });
		A[t].right = A.size() - 1;
		return t;
	}
	if (x < A[t].key)
	{
		r = 0;
		if (A[t].left != -1)
		{
			r = A[t].left;
		}
		r = treeInsert(A, r, x);
		return t;
	}
	else
	{
		r = 0;
		if (A[t].right != -1)
		{
			r = A[t].right;
		}
		r = treeInsert(A, r, x);
		return t;
	}
}


int deleteNode(std::vector<node>& A, int r)
{
	int i;
	int s;
	int parents;
	int temp;
	i = r;
	if (A[i].left == -1 && A[i].right == -1)
	{
		//A[i].key = NULL;
		return -1;
	}
	else if (A[i].left == -1 && A[i].right != -1)
	{
		//A[i].key = NULL;
		return A[i].right;
	}
	else if (A[i].left != -1 && A[i].right == -1)
	{
		//A[i].key = NULL;
		return A[i].left;
	}
	else
	{
		s = A[i].right;
		while (A[s].left != -1)
		{
			parents = s;
			s = A[s].left;
		}
		A[i].key = A[s].key;
		if (s == A[i].right)
		{
			A[i].right = A[s].right;
		}
		else
		{
			A[parents].left = A[s].right;
		}
		return i;
	}

}

void treeDelete(std::vector<node>& A,int t, int x)
{
	int r;					//deleted node
	int pl = NULL;			//left parents
	int pl_flag = 0;
	int pr = NULL;			//right parents
	int pr_flag = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].key == x)
		{
			r = i;
			break;
		}
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].left == r)
		{
			pl = i;
			pl_flag++;
			break;
		}
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].right == r)
		{
			pr = i;
			pr_flag++;
			break;
		}
	}
	if (t == r)
	{
		r = deleteNode(A, t);
	}
	else if (pl_flag)
	{
		A[pl].left = deleteNode(A, r);
	}
	else if (pr_flag)
	{
		A[pr].right = deleteNode(A, r);
	}
	
}
void preTraversal(std::vector<node>& A, int i)
{
	if (A[i].key)
	{
		std::cout << A[i].key << " ";
	}
	if (A[i].left != -1)
	{
		preTraversal(A, A[i].left);
	}
	if (A[i].right != -1)
	{
		preTraversal(A, A[i].right);
	}
}

void inTraversal(std::vector<node>& A, int i)
{
	if (A[i].left != -1)
	{
		inTraversal(A, A[i].left);
	}
	if (A[i].key)
	{
		std::cout << A[i].key << " ";
	}
	if (A[i].right != -1)
	{
		inTraversal(A, A[i].right);
	}
}

void postTraversal(std::vector<node>& A, int i)
{
	if (A[i].left != -1)
	{
		postTraversal(A, A[i].left);
	}
	if (A[i].right != -1)
	{
		postTraversal(A, A[i].right);
	}
	if (A[i].key)
	{
		std::cout << A[i].key << " ";
	}
}


int main()
{
	int n, x,order;
	int t = 0;
	std::cin >> n;
	std::vector<int> T(n);
	std::vector<node> A(1);
	A[0] = { NULL,-1,-1 };
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		T[i] = treeInsert(A, t, x);
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (!A[i].key)
		{
			for (int k = 0; k < A.size(); k++)
			{
				if (A[k].left == i)
				{
					A[k].left = -1;
				}
				if (A[k].right == i)
				{
					A[k].right = -1;
				}
			}
		}
	}
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> order >> x;
		treeDelete(A, t, x);
		if (order == 0)
		{
			preTraversal(A, 0);
			std::cout << std::endl;
		}
		if (order == 1)
		{
			inTraversal(A, 0);
			std::cout << std::endl;
		}
		if (order == 2)
		{
			postTraversal(A, 0);
			std::cout << std::endl;
		}
	}
	
}