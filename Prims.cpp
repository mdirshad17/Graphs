// CTRL+ALT+M
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define ff first
#define ss second
#define deb(x) cout << #x << " " << x << endl;
#define all(x) x.begin(), x.end()
#define endl "\n"
const int maxn = 1e5;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort
//todo For a Tree its shortest Path in  dfs is same as in bfs if it is acyclic
// *! Bridge Detection:: From Backedge we take low[u]=min(low[u],tin[x])
// *! Bridge Detection:: From Child we take low[u]=min(low[u],low[x])
// *! Bridge Detection:: this is a bridge if(low[x]>tin[u])
// vi adj[maxn];
// int visited[maxn];
void Prims(vector<vi> edge)
{
  int n = edge.size();
  vi par(n, -1);
  vi wt(n, inf);
  vi visited(n, 0);
  wt[0] = 0;
  int totalweight = 0;
  for (int i = 0; i < n; i++)
  {
    // **Selecting the Min wt Edge
       int v = -1;
    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && (v == -1 || wt[j] < wt[v]))
      {
        v = j;
      }
    }
    // ** If the (wt[v]==inf) then there is no mst 
    // ** This condition is only possible if the graph is not connected
    if (wt[v] == inf)
    {
      cout << "NO MST\n";
      return;
    }
    if (par[v] != -1)
    {
      cout << par[v] << " " << v << endl;
    }
    totalweight += wt[v];
    // ** Finding all the neighbours of min  wt
    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && edge[v][j] < wt[j])
      {
        wt[j] = edge[v][j];
        par[j] = v;
      }
    }visited[v]=1;
  }
  cout << totalweight << endl;
}
void runcases(int T)
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<int>> edge(n, vector<int>(n, inf));
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    edge[x][y] = w;
    edge[y][x] = w;
  }

  Prims(edge);

  //cout<<"Case #"<<T<<": ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  //cin >> T;
  for (int t = 1; t <= T; t++)
  {
    runcases(t);
  }

  return 0;
}
