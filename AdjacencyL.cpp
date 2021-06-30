#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v[], int n)
{	cout << "\nAdjacency List Traversal\n";
	for (int i = 0; i < n; i++)
	{	cout << i << ": ";
		for (int x : v[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return ;
}
void BFS(vector<int> v[], int n)
{
	cout << "\nBFS Traversal\n";
	bool * visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty())
	{
		int size = q.size();
		while (size--) {
			int d = q.front();
			q.pop();
			cout << d << " ";
			for (int x : v[d])
			{
				if (!visited[x])
				{
					q.push(x);
					visited[x] = true;
				}
			}
		} cout << endl;

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
	print(v, n);
	BFS(v, n);
	return 0;

}