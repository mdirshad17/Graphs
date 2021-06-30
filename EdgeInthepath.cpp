#include <bits/stdc++.h>
using namespace std;
// vector<bool> visited;
// vector<int> parent;


void bfs(vector<int> adj[],int s,int e,int n,vector<int> &dist)
{
	queue<int> q;
	q.push(s);
	vector<bool> visited(n,false);
	visited[s]=true;
	while(!q.empty())
	{
		  int d=q.front();
		  q.pop();
		  if(d==e)
		  {
		  	return;
		  }
		  for(int x:adj[d])
		  {
            if(!visited[x])
            {
            	dist[x]=dist[d]+1;
            	q.push(x);
            	visited[x]=true;
            }
		  }
	}
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
	int a,b;
	cin>>a>>b;
	vector<int> dista(n,0);
	vector<int> distb(n,0);
	bfs(adj,a,b,n,dista);
	bfs(adj,b,a,n,distb);
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<dista[i]<<" ";
	// }cout<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<distb[i]<<" ";
	// }cout<<endl;
	for(int i=0;i<3;i++)
	{
		int x,y;
		cin>>x>>y;
		if((dista[x]+distb[y]+1)==dista[b])
		{
			cout<<"YES IN THE PATH  :"<<x<<" "<<y<<endl;
		}else cout<<"NOT IN THE PATH"<<endl;
	}


}