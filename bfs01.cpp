#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> parent;
vector<int> dist;

void shortpath(vector<pair<int, int> > adj[], int s)
{
	deque<int> dq;
	dq.push_front(s);
	visited[s] = true;
	dist[s] = 0;
	while (!dq.empty())
	{
		int d = dq.front();
		dq.pop_front();
		for (auto x : adj[d])
		{
			int u = x.first;
			int w = x.second;
			if (dist[u] > w + dist[d])
			{
				dist[u] = w + dist[d];
				parent[u] = d;
				if (w == 1)
				{
					dq.push_back(u);
				} else dq.push_front(u);
			}

		}
	}
}
int main()
{
	int n, e;
	cin >> n >> e;
	vector<pair<int, int> > adj[n];
	for (int i = 0; i < e; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	} visited.assign(n, false);
	parent.assign(n, -1);
	dist.assign(n, INT_MAX);
	shortpath(adj, 0);

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j != -1; j = parent[j])
		{
			cout << j << " ";
		} cout << endl;
	} cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << dist[i] << " ";
	}

}