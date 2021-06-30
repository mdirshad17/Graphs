#include <bits/stdc++.h>
using namespace std;
bool haspath(vector<int> v[],int n,int sp,int ep)
{ bool * visited=new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i]=false;
	}
	visited[sp]=true;
   queue<int> q;
   q.push(sp);
   while(!q.empty())
   {
   	int d=q.front();
   	q.pop();
   	if(d==ep)
   	{
   		return true;
   	}
   	for( auto x: v[d])
   	{
   		if(!visited[x])
   		{
   			q.push(x);
   			visited[x]=true;
   		}
   	}

   }
return false;
}
int main()
{
	int n;
	cin>>n;
	int e;
	cin>>e;
	vector<int> v[n];
	for (int i = 0; i < e; ++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int sp,ep;
	cin>>sp>>ep;
	cout<<haspath(v,n,sp,ep);
    return 0;

}