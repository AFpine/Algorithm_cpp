#include <iostream>
#include <vector>
#include <set>

static const int INF = 100000000;
static int total = 0;

struct V
{
	int d;
	bool selected;
};

struct E
{
	int weight;
	int V1;
	int V2;
};

int ExtractMin(std::vector<V>& Q)
{
	int u=0;
	int min = INF;
	for (int i = 1; i < Q.size(); i++)
	{
		if (Q[i].selected==false && min > Q[i].d)
		{
			min = Q[i].d;
			u = i;
		}
	}
	return u;
}

void Dijkstra(std::vector<E>& G, std::vector<V>& V, std::vector<int>& prev,int r)
{
	int s = 0;
	int u;
	int v;
	V[r].d = 0;
	while (s != V.size()-1)
	{
		u = ExtractMin(V);
		if (u == 0)
		{
			break;
		}
		V[u].selected = true;
		s++;
		for (int i = 0; i < G.size(); i++)
		{
			if (G[i].V1 == u)
			{
				v = G[i].V2;
				if (V[v].selected == false && (V[u].d + G[i].weight) < V[v].d)
				{
					V[v].d = V[u].d + G[i].weight;
					prev[v] = u;
				}
			}
		}
	}
}


int main()
{
	int v, e;
	int r, t;
	std::cin >> v >> e;
	std::vector<E>G(e);
	std::vector<V>V(v + 1);
	std::vector<int>prev(v+1,0);
	for (int i = 0; i < e; i++)
	{
		int v1, v2, w;
		std::cin >> v1 >> v2 >> w;
		G[i].V1 = v1;
		G[i].V2 = v2;
		G[i].weight = w;
	}
	std::cin >> r >> t;
	for (int i = 1; i < V.size(); i++)
	{
		V[i].d = INF;
		V[i].selected = false;
	}
	
	Dijkstra(G,V,prev,r);

	for (int i = 1; i < prev.size(); i++)
	{
		std::cout << prev[i] << " ";
	}
	if (V[t].d == INF)
	{
		std::cout << "Impossible ";
	}
	else
	{
		std::cout << V[t].d;
	}
}