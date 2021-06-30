// Detecting Cycle in A Graph Using DFS

#include <bits/stdc++.h>
using namespace std;
bool IsCyClicDFS(vector<int> v[], int sv, bool * visited, bool * recs)
{
	visited[sv] = true;
	recs[sv] = true;
	for (int x : v[sv])
	{
		if (!visited[x] && IsCyClicDFS(v, x, visited, recs))
		{
			return true;
		} else if (recs[x])
		{
			return true;
		}
	}
	recs[sv] = false;
	return false;
}
bool IsCyClic(vector<int> v[], int n)
{
	bool * visited = new bool[n];
	bool * recs = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		recs[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && IsCyClicDFS(v, i, visited, recs))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int n, e;
	cin >> n >> e;
	vector<int> v[n];
	for (int i = 0; i < e; ++i)
	{	int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		// v[y].push_back(x);
	}
	cout << IsCyClic(v, n) << " ";
	return 0;

}