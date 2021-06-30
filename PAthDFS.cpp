#include <bits/stdc++.h>
using namespace std;
void haspath(vector<int> v[],int sp,bool * visited)
{ 
  visited[sp]=true;
  for(auto x:v[sp])
  {
  	if(!visited[x])
  	{
  		haspath(v,x,visited);
  	}
  }

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
	bool * visited=new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i]=false;
	}

	haspath(v,sp,visited);
	cout<<(visited[ep]);

    return 0;

}