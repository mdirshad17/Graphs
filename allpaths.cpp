// All the Paths From A source to Destination
//


#include<bits/stdc++.h>
using namespace std;
vector<int> v;

void dfs(vector<int> *adj, int s, bool * visited, int ev)
{	if (s == ev)
	{	cout << "distance " << v.size() << " \n";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		} cout << s << endl;
		return;

	}
	visited[s] = true;

	for (int x : adj[s])
	{
		if (!visited[x])
		{	v.push_back(s);
			dfs(adj, x, visited, ev);
			v.pop_back();

		}
	}

}
int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	vector<int> adj[n];
	for (int i = 0; i < e; i++)
	{
		int s, d;
		cin >> s >> d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	cout << "Enter the End Vertex\n";
	int ev;
	cin >> ev;
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	dfs(adj, 0, visited, ev);
}