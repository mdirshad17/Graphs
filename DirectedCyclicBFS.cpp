// cycle detection using Kahn Algorithm

#include <bits/stdc++.h>
using namespace std;
bool IsCyClicBFS(vector<int> v[], int n)
{	vector<int> indegree(n, 0);
	for (int i = 0; i < n; i++) {
		for (int x : v[i])
		{
			indegree[x]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	int count = 0;

	while (!q.empty())
	{
		int d = q.front();
		q.pop();
		for (int x : v[d])
		{
			--indegree[x];
			if (indegree[x] == 0)
			{
				q.push(x);
			}
		}
		count++;
	}
	cout << count << " \n";
	return (count != n);

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
	cout << IsCyClicBFS(v, n) << " ";
	return 0;

}