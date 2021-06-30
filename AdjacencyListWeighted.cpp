#include <bits/stdc++.h>
using namespace std;
void print(vector<pair<int,int> >adj[],int n)
{  cout<<"Weighted List printing\n";
	for (int i = 0; i <n; ++i)
	{   
		for(auto x:adj[i])
		{   cout<<i<<" ";
			cout<<x.first<<" "<<x.second<<endl;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> > adj[n];
	int e;
	cin>>e;
	for (int i = 0; i < e; ++i)
	{
		int s,p,w;
		cin>>s>>p>>w;
		adj[s].push_back(make_pair(p,w));
	}
	print(adj,n);
	return 0;
}