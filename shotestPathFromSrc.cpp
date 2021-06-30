#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>  pd;
void GetShortPath(vector<pd> v[],int n,int src)
{
	vector<int> indeg(n,0);
	for (int i = 0; i <n; ++i)
	{
		for(auto x:v[i])
		{
			indeg[x.first]++;
		}
	}
	queue<int> q;
for (int i = 0; i < n; ++i)
{
   if(indeg[i]==0)
   {
   	q.push(i);
   }
}
std::vector<int> top;
while(!q.empty())
{
   int d=q.front();
q.pop();
top.push_back(d);
for(auto x: v[d])
{
--indeg[x.first];
if(indeg[x.first]==0)
{
	q.push(x.first);
}

}
}

vector<int> dist(n,INT_MAX);
dist[src]=0;
for (int i = 0; i < n; ++i)
{
	for(auto x:v[top[i]])
	{
     if(dist[top[i]]==INT_MAX)
     {
     	continue;
     }else
     {
     	if(dist[x.first]>dist[top[i]]+x.second)
     	{
     		dist[x.first]=dist[top[i]]+x.second;
     	}
     }

	}
}
for (int i = 0; i < n; ++i)
{
	cout<<dist[i]<<" ";
}
return ;
}
int main()
{  int n;
	cin>>n;
	std::vector<pd> v[n];
	int e;
	cin>>e;
	for (int i = 0; i < e; ++i)
	{
		int s,p,w;
		cin>>s>>p>>w;
		v[s].push_back({p,w});
	}
	int src;
	cin>>src;
	GetShortPath(v,n,src);
	return 0;
}