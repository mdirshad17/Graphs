#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define hM 9999999900000001
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpi vector<pair<int,int>>
#define pii pair<int,int>
#define pb push_back
#define inf 1e18
#define ff first
#define ss  second
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(x) x.begin(),x.end()
#define endl "\n"
const int maxn = 1e5;
vector<vi> adj;
int n, m;
vi bellman_Ford(int src)
{
	vi d(n + 1, inf);
	d[src] = 0;

	for (int i = 0; i < (n - 1); i++)
	{
		vi copy = d;
		for (vi x : adj)
		{
			int u = x[0], v = x[1], w = x[2];
			if (d[u] != inf)
			{
				if (d[u] + w < copy[v])
				{
					copy[v] = (d[u] + w);
				}
			}
		}
		d = copy;
	}
	return d;
}
void runcases(int T)
{

	cin >> n >> m;
	adj.resize(n + 1);
	while (m--)
	{
		// directed edges
		int x, y, w;
		adj.pb({x, y, w});
	}
	int src;
	cin >> src;
	vi d = bellman_Ford(src);
	for (int x : d)
	{
		cout << x << " ";
	} cout << endl;



	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
