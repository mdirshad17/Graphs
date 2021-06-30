#include <bits/stdc++.h>
using namespace std;
bool IsCyClicBFS(vector<int> v[], int sv, bool * visited, int  n)
{
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  int * parent = new int[n];

  for (int i = 0; i < n; ++i)
  {
    parent[i] = -1;
  }

  while (!q.empty())
  {
    int d = q.front();
    q.pop();
    for (int x : v[d])
    {
      if (!visited[x])
      {
        q.push(x);
        parent[x] = d;
        visited[x] = true;
      } else if (x != parent[d])
      {
        return true;
      }



    }
  }
  return false;
}
bool IsCyClic(vector<int> v[], int n)
{
  bool * visited = new bool[n];
  for (int i = 0; i < n; ++i)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; ++i)
  {
    if (!visited[i] && IsCyClicBFS(v, i, visited, n))
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
  { int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cout << IsCyClic(v, n) << " ";
  return 0;

}