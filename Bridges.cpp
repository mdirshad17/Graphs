// Removing Edges Increase the number of connected Components
// the this Edge is a backEdge

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin;
vector<int> low;
int timer;

//   \
//     \
// 0--1--2--3
void dfs_bridge(int s, int par)
{
	visited[s] = true;
	in[s] = low[s] = timer++;
	for (int x : adj[s])
	{
		if (x == par)
		{
			continue;
		} else if (visited[x])
		{
			// backedge
			low[s] = min(low[s], tin[x]);
		} else
		{
			dfs_bridge(x, s);
			low[s] = min(low[s], low[x]);
			if (low[x] > tin[s])
				cout << s << " " << x << " " << "This is a bridge\n";
		}

	}

}
int main()
{
	int n;
	cin >> n;
	adj.assign(n + 1, vector<int> ());
	int m;
	cin >> m;
	int x, y;
	while (m--)
		cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);


	visited.assign(n, false);
	in.assign(n + 1, -1);
	low.assign(n + 1, -1);
	for (int i = 0; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs_bridge(i, -1);
		}
	}
}