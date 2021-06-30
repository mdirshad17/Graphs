// 603 DIV2 D
// **********

#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef vector<int> vi;
typedef pair<int, int> pii;
vector<bool> visited;
void dfs(vector<int> adj[], int s)
{
  visited[s] = true;
  for (int x : adj[s])
  {
    if (!visited[x])
    {
      dfs(adj, x);
    }
  }
}
void runcases(int T)
{

  int n;
  cin >> n;
  string s;
  unordered_map<int, vector<int> > m;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (char c : s)
    {
      m[c - 'a'].push_back(i);
    }
  }
  vector<int> adj[n];
  for (auto x : m)
  {
    vector<int> v = x.second;
    if (v.size() > 1)
    {
      int sz = v.size();
      for (int i = 0; i < (sz - 1); i++)
      {
        adj[v[i]].push_back(v[i + 1]);
        adj[v[i + 1]].push_back(v[i]);
      }
    }
  }
  visited.assign(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      dfs(adj, i);
      ans++;
    }
  }
  cout << ans;
  return;



  //cout<<"Case #"<<T<<": ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int T = 1;
  //cin >> T;
  for (int t = 1; t <= T; t++) {
    runcases(t);
  }

  return 0;
}
