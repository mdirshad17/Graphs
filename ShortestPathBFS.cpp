#include <bits/stdc++.h>
using namespace std;
void getpath(vector<int> v[], int n, int sp, int ep)
{
  bool * visited = new bool[n];
  for (int i = 0; i < n; ++i)
  {
    visited[i] = false;
  }
  std::map<int, int> m;
  visited[sp] = true;
  queue<int> q;
  q.push(sp);
  while (!q.empty())
  {
    int d = q.front();
    q.pop();
    if (d == ep)
    {
      while (d != sp)
      {
        cout << d << " ";
        d = m[d];
      }
      cout << d << " ";
    }
    for ( auto x : v[d])
    {
      if (!visited[x])
      {
        q.push(x);
        m[x] = d;
        visited[x] = true;
      }
    }

  }
}
bool haspath(vector<int> v[], int n, int sp, int ep)
{ bool * visited = new bool[n];
  for (int i = 0; i < n; ++i)
  {
    visited[i] = false;
  }
  visited[sp] = true;
  queue<int> q;
  q.push(sp);
  while (!q.empty())
  {
    int d = q.front();
    q.pop();
    if (d == ep)
    {
      return true;
    }
    for ( auto x : v[d])
    {
      if (!visited[x])
      {
        q.push(x);
        visited[x] = true;
      }
    }

  }
  return false;
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
  int sp, ep;
  cin >> sp >> ep;
  if (haspath(v, n, sp, ep))
  { cout << "It has path\n";
    getpath(v, n, sp, ep);
    return 0;
  }
  cout << "It doesn't have path\n
       return 0;

     }