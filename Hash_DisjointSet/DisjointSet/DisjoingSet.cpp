#include <iostream>
#include <vector>

static int count = 0;

struct link
{
	link* head_pointer = nullptr;
	int key = NULL;
	link* next_pointer = nullptr;
};

int find_next(const std::vector<link>& L, int x)
{
	if (L[x].next_pointer != &L[x])
	{
		return find_next(L, L[x].next_pointer->key);
	}
	else
	{
		return x;
	}
}

void set_head(std::vector<link>& L, int x, int y)
{
	if (L[y].next_pointer != &L[y])
	{
		L[y].head_pointer = L[x].head_pointer;
		set_head(L, x, L[y].next_pointer->key);
	}
	else
	{
		L[y].head_pointer = L[x].head_pointer;
	}
}

void num_of_group(std::vector<link>& L, int x)
{
	count++;
	if (L[x].next_pointer != &L[x])
	{
		num_of_group(L, L[x].next_pointer->key);
	}
}

int main()
{
	int temp;
	int head;
	int n, m;
	int max = 0;
	int x, y;
	std::cin >> n >> m;
	std::vector<link> list(n + 1);
	for (int i = 1; i <= n; i++)
	{
		list[i].head_pointer = &list[i];
		list[i].next_pointer = &list[i];
		list[i].key = i;
	}
	for (int i = 0; i < m; i++)
	{
		std::cin >> x >> y;
		if (list[x].head_pointer != list[y].head_pointer)
		{
			head = list[y].head_pointer->key;
			set_head(list,x,head);
			temp = find_next(list, x);
			list[temp].next_pointer = &list[head];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		num_of_group(list, i);
		if (count >= max)
		{
			max = count;
		}
	}
	std::cout << max;
}