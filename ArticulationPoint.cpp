// Removing a point increases the number of connected component
// cut vertex
#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> in;
vector<int> low;
vector<vector<int> > adj;
int timer;
set<int> APs;
void dfs_AP(int s, int par = -1)
{
	visited[s] = true;
	in[s] = low[s] = timer++;
	int children = 0;
	for (int x : adj[s])
	{
		if (x == par)
			continue;
		if (visited[x]) {
			low[s] = min(low[s], in[x]);
		}
		else
		{
			dfs_AP(x, s);
			low[s] = min(low[s], low[x]);

			if (low[x] >= in[s] && par != -1)
				APs.insert(s);

			children++;
		}
	}
	if (par == -1 && children > 1)
		APs.insert(s);
}
int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	adj.assign(n, vector<int> ());
	int x, y;
	while (m--)
		cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

	visited.assign(n, false);
	timer = 1;
	in.assign(n, 0);
	low.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs_AP(i);
		}
	}
	cout << "Total No of Articulation Point " << APs.size() << endl;

	for (int x : APs)
		cout << x << " ";
}