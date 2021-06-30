#include <bits/stdc++.h>
using namespace std;
void TopologicalSort(vector<int> v[], int n)
{

	vector<int> indeg(n, 0);
	// no of incoming edges
	for (int i = 0; i < n; ++i)
	{
		for (int x : v[i])
		{
			indeg[x]++;
		}
	}
	queue<int> q;
	// kahn algorithm
	// topolgical sort
	for (int i = 0; i < n; ++i)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int d = q.front();
		q.pop();
		cout << d << " ";
		for (int i : v[d])
		{
			--indeg[i];
			if (indeg[i] == 0)
			{
				q.push(i);
			}
		}
	}

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

	}
	TopologicalSort(v, n);
	return 0;

}