#include <bits/stdc++.h>
using namespace std;
// vector<bool> visited;
// vector<int> parent;


int shortcycle(vector<int> adj[],int s,int n)
{
	queue<int> q;
	q.push(s);
    vector<int> dist(n,0);
	vector<bool> visited(n,false);
	vector<int> parent(n,-1);
	// visited[s]=true;
	// dist[s]=0;
	visited[s]=true;
	while(!q.empty())
	{
		  int d=q.front();
		  q.pop();
		  for(int x:adj[d])
		  {
            if(!visited[x])
            {
            	dist[x]=dist[d]+1;
            	q.push(x);
            	visited[x]=true;
            	parent[x]=d;

            }else if(x!=parent[d])
            {
              return dist[d]+dist[x]+1;
            }
		  }
	}
	return -1;
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
	int cyclelength=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(shortcycle(adj,i,n)!=-1)
		{
			cyclelength=min(cyclelength,shortcycle(adj,i,n));
		}
	}
	cout<<cyclelength<<" ";

}