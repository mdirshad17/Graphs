/*Connected Components in a Graph*/

#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int> v[], int i, bool * visited)
{
	cout << i << " ";
	visited[i] = true;
	for (int x : v[i])
	{
		if (!visited[x])
		{
			DFS(v, x, visited);
		}
	}

}
// This is for the If there are multiple connected components
void GetCC(vector<int> v[], int n)
{	cout << "Connecting Components\n";
	bool * visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			DFS(v, i, visited);
			cout << endl;
		}
	}

}
int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	vector<int> v[n];
	for (int i = 0; i < e; ++i)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	GetCC(v, n);
	return 0;
}
