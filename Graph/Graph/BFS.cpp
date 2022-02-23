#include <iostream>
#include <vector>
#include <queue>

void BFS(std::vector<std::vector<int>>& G, std::vector<bool>& visited, int s);

int main()
{
	int V, E, s;
	std::cin >> V >> E;
	std::vector<std::vector<int>> G(V+1, std::vector<int>(V+1, 0));
	std::vector<bool> visited(V + 1, false);

	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		std::cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}

	std::cin >> s;
	BFS(G, visited, s);
	for (int i = 1; i < V; i++)
	{
		BFS(G, visited, i);
	}
	return 0;
}

void BFS(std::vector<std::vector<int>>& G, std::vector<bool>& visited, int s)
{
	int u;
	std::queue<int> queue;
	if (visited[s] == false)
	{
		visited[s] = true;
		std::cout << s << " ";
		queue.push(s);
	}
	while (!queue.empty())
	{
		u = queue.front();
		queue.pop();
		for (int i = 1; i < G.size(); i++)
		{
			if (G[u][i] == 1 && visited[i] == false)
			{
				visited[i] = true;
				std::cout << i << " ";
				G[u][i] = 0;
				G[i][u] = 0;
				queue.push(i);
			}
		}

	}
}