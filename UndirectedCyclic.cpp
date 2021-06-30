// This is a dfs based solution

// from parent to child

#include <bits/stdc++.h>
using namespace std;
bool IsCyClicDFS(vector<int> v[], int sv, bool *visited, int parent)
{
	visited[sv] = true;
	for (int x : v[sv])
	{
		if (!visited[x])
		{
			if (IsCyClicDFS(v, x, visited, sv))
			{
				return true;
			}
		}
		else if (x != parent)
		{
			return true;
		}
	}
	return false;
}
bool IsCyClic(vector<int> v[], int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			if (IsCyClicDFS(v, i, visited, -1))
			{
				return true;
			}
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
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << IsCyClic(v, n) << " ";
	return 0;
}