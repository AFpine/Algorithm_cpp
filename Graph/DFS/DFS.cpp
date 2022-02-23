#include <iostream>
#include <vector>
#include <queue>

void DFS(std::vector<std::vector<int>>& G, std::vector<bool>& visited, int s);

int main()
{
	int V, E, s;
	std::cin >> V >> E;
	std::vector<std::vector<int>> G(V + 1, std::vector<int>(V + 1, 0));
	std::vector<bool> visited(V + 1, false);

	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		std::cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}

	std::cin >> s;
	DFS(G, visited, s);
	for (int i = 1; i < V; i++)
	{
		DFS(G, visited, i);
	}
	return 0;
}

void DFS(std::vector<std::vector<int>>& G, std::vector<bool>& visited, int s)
{
	if (visited[s] == false)
	{
		visited[s] = true;
		std::cout << s << " ";
		for (int i = 1; i < G.size(); i++)
		{
			if (G[s][i] == 1 && visited[i] == false)
			{
				G[s][i] = 0;
				G[i][s] = 0;
				DFS(G, visited, i);
			}
		}
	}
}
