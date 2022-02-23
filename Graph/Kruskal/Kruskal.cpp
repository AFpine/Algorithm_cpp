#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

static int total = 0;

struct E
{
	int weight;
	int V1;
	int V2;
};

void Kruskal(std::vector<E>& G, int v);

int main()
{
	int v, e;
	std::cin >> v >> e;
	std::vector<E>G(e);
	for (int i = 0; i < e; i++)
	{
		int v1, v2, w;
		std::cin >> v1 >> v2 >> w;
		G[i].V1 = v1;
		G[i].V2 = v2;
		G[i].weight = w;
	}
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 1; j < G.size(); j++)
		{
			if (G[j].weight <= G[j - 1].weight)
			{
				E emp;
				emp = G[j];
				G[j] = G[j - 1];
				G[j - 1] = emp;
			}
		}
	}

	Kruskal(G, v);
	std::cout << total;
}

void Kruskal(std::vector<E>&G, int v)
{
	std::set<std::set<int>>A;
	std::set<std::set<int>>V;
	std::set<std::set<int>>::iterator it;
	std::set<int>set_u;
	std::set<int>set_v;
	std::set<std::set<int>>::iterator it_u;
	std::set<std::set<int>>::iterator it_v;
	std::set<int>::iterator it_in;
	for (int i = 1; i <= v; i++)
	{
		std::set<int>s;
		s.insert(i);
		V.insert(s);
	}
	for (int i = 0; i < G.size(); i++)
	{
		for (it = V.begin(); it != V.end(); it++)
		{
			if (it->find(G[i].V1) != it->end())
			{
				it_u = it;
				set_u = *it;
			}
			if (it->find(G[i].V2) != it->end())
			{
				it_v = it;
				set_v = *it;
			}
		}
		if(set_u != set_v)
		{
			std::cout << G[i].weight << " ";
			total += G[i].weight;
			std::set<int>s;
			A.insert(set_u);
			A.insert(set_v);
			for (it_in = set_u.begin(); it_in != set_u.end(); it_in++)
			{
				s.insert(*it_in);
			}
			for (it_in = set_v.begin(); it_in != set_v.end(); it_in++)
			{
				s.insert(*it_in);
			}
			V.erase(it_u);
			V.erase(it_v);
			V.insert(s);
		}
	}
}