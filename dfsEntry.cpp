#include <bits/stdc++.h>
using namespace std;
// vector<bool> visited;
// vector<int> parent;

vector<bool> visited;
vector<int> Ent,Ext;
int dfstimer=0;
void dfs(vector<int> adj[],int s)
{
	visited[s]=true;
	Ent[s]=dfstimer++;
	for(int x:adj[s])
	{
		if(!visited[x])
		{
			dfs(adj,x);
		}
	}
	Ext[s]=dfstimer++;
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visited.assign(n,false);
	Ent.assign(n,-1);
	Ext.assign(n,-1);
	dfs(adj,0);
	for(int i=0;i<n;i++)
	{
		cout<<Ent[i]<<" "<<Ext[i]<<endl;
	}


}
