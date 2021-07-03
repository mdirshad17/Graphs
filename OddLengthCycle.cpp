// vector<int> visited;
int visited[255];
int ans = 0;
void dfs(int s, vector<vector<int> > & adj, int lv = 0)
{
  visited[s] = lv;

  for (auto x : adj[s])
  {
    if (visited[x] != -1)
    {
      int l = (visited[s]);
      int m = visited[x];
      int diff = abs(l - m);
      if ((diff & 1) == 0)
        ans = 1;

    } else dfs(x, adj, lv + 1);

  }


}
bool solve(vector<vector<int>>& graph)
{
  ans = 0;
  memset(visited, -1, sizeof(visited));
//    for(auto x:graph){}
  int n = graph.size();
  for (int i = 0; i < n; i++)
  {
    if (visited[i] == -1)
    {
      dfs(i, graph);
      if (ans)
        return 1;
    }
  }
  return 0;
}
