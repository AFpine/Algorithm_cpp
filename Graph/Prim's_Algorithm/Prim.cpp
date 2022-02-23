#include <iostream>
#include <vector>
#include <set>

void Prim(std::vector<std::vector<int>>& G, std::vector<bool>& visited);
void ExtractMin(std::vector<std::vector<int>>& G, std::vector<bool>& selected);
static int count = 0;
static int sum = 0;

int main()
{
	int V, E;
	std::cin >> V >> E;
	std::vector<std::vector<int>> G(V + 1, std::vector<int>(V + 1, -1));
	std::vector<bool> selected(V + 1, false);

	for (int i = 0; i < E; i++)
	{
		int v1, v2, w;
		std::cin >> v1 >> v2 >> w;
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
	for (int i = 1; i <= V; i++)
	{	
		G[i][i] = 10000000;			//10 million
	}
	G[1][1] = 0;
	Prim(G, selected);
	std::cout << sum;
	return 0;
}

void Prim(std::vector<std::vector<int>>& G, std::vector<bool>& selected)
{
	while (count != G.size()-1)
	{
		for (int i = 1; i < G.size(); i++)
		{
			if (selected[i] == true)
			{
				for (int j = 1; j < G.size(); j++)
				{
					if (G[i][j] != -1&&(j!=i))
					{
						if (G[j][j] > G[i][j])
						{
							G[j][j] = G[i][j];
						}
					}
				}
			}
		}
		ExtractMin(G,selected);
	}
}

void ExtractMin(std::vector<std::vector<int>>& G, std::vector<bool>& selected)
{
	int u;
	int min = 10000000;
	for (int i = 1; i < G.size(); i++)
	{
		if (selected[i] == false && G[i][i]<min)
		{
			min = G[i][i];
			u = i;
		}
	}
	selected[u] = true;
	sum += G[u][u];
	count++;
	std::cout << u << " ";
}