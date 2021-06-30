#include   <bits/stdc++.h>
using      namespace std;
#define    M 1000000007
#define    hM 9999999900000001
#define    int long long int
#define    vi vector<int>
#define    vb vector<bool>
#define    vc vector<char>
#define    vpi vector<pair<int,int>>
#define    pii pair<int,int>
#define    pb push_back
#define    inf 1e18
#define    ff first
#define    ss  second
#define    deb(x) cout<<#x<<" "<<x<<endl;
#define    all(x) x.begin(),x.end()
#define    endl "\n"
const int maxn = 1e5;
vector<vector<pii>> adj;

int n, m;
vector<vi> dijkstra(int src) {


	set<vi> st;
	vi d(n + 1, inf);
	// getting the path using the parents
	vi par(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		par[i] = -1;
	}
	par[src] = src;
	// wt and node

	st.insert({0, src});
	d[src] = 0;
	while (!st.empty())
	{
		auto it = st.begin();
		int idx = (*it)[1];
		st.erase(it);
		for (auto x : adj[idx])
		{
			int nb = x.ff;
			int wt = x.ss;
			if (d[nb] > d[idx] + wt)
			{
				par[nb] = idx;
				st.erase({d[nb], nb});
				d[nb] = wt + d[idx];
				st.insert({d[nb], nb});
			}
		}
	}
	return {d, par};
}
vector<vi> MultiSourcedijkstra(vi  src) {


	set<vi> st;
	vi d(n + 1, inf);
	// getting the path using the parents
	vi par(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		par[i] = -1;
	}
	// par[src] = src;
	// wt and node

	// st.insert({0, src});
	for (int x : src)
	{
		st.insert({0, x});
		par[x] = x;
		d[x  ] = 0;
	}

	while (!st.empty())
	{
		auto it = st.begin();
		int idx = (*it)[1];
		st.erase(it);
		for (auto x : adj[idx])
		{
			int nb = x.ff;
			int wt = x.ss;
			if (d[nb] > d[idx] + wt)
			{
				par[nb] = idx;
				st.erase({d[nb], nb});
				d[nb] = wt + d[idx];
				st.insert({d[nb], nb});
			}
		}
	}
	return {d, par};
}
void getPath(int s, vi & par, vi & d)
{
	if (d[s] == inf)
	{
		cout << "No Path\n";
		return;
	}
	if (par[s] == s)
	{
		cout << s << "->";
		return;
	}
	getPath(par[s], par, d);
	cout << s << "->";
}
void runcases(int T)
{
	cin >> n >> m;
	adj.resize(n + 1);
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	vector<vi> d = dijkstra(1);
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << d[0][i] << endl;
	}
	cout << " :: Parent \n";
	// Printing the Parent
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t";
		getPath(i, d[1], d[0]);
		cout << endl;
	}


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
