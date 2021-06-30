// BFS of the Graph

#include<bits/stdc++.h>
using namespace std;
vector<int> dist;
vector<int> parent;
vector<int> visited;
void bfs(vector<int> adj[], int s, int n)
{	dist.assign(n, 0);
	parent.assign(n, -1);
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int d = q.front();
		q.pop();
		for (int x : adj[d])
		{
			if (!visited[x])
			{
				visited[x] = true;
				q.push(x);
				parent[x] = d;
				dist[x] = dist[d] + 1;
			}
		}
	}
}
int main()
{
	int n, e;
	cin >> n >> e;
	vector<int> adj[n];
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visited.assign(n, false);
	bfs(adj, 0, n);
	for (int i = 1; i < n; i++)
	{
		if (visited[i])
		{
			cout << dist[i] << endl;
			for (int j = i; j != -1; j = parent[j])
			{
				cout << j << " ";
			} cout << endl;

		}

	}


}