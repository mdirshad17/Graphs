#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int> v[],int i,bool * visited,stack<int> & s)
{   visited[i]=true;
	for(int x:v[i])
	{
       if(!visited[x])
       {
       	DFS(v,x,visited,s);
       }
	}
	s.push(i);
}
void TopologicalSort(vector<int> v[],int n)
{
	bool * visited=new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i]=false;
	}
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i])
		{
			DFS(v,i,visited,s);
		}
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> v[n];
	for (int i = 0; i < e; ++i)
	{ int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	
	}
	TopologicalSort(v,n);
	return 0;

}