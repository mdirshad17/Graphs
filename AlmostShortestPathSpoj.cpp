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
//  int BIT[maxn];
// void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
// int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
vector<vpi> adj;
int n, m;
int src, dst;
vector<vi> matrix;
void destroy_parents(int dst, vector<set<int>> & pars)
{
	if (pars[dst].size() == 0)
	{
		return;
	}
	for (int x : pars[dst])
	{
		matrix[x][dst] = inf;
		destroy_parents(x, pars);
	}
}
void dij(int fl)
{
	vi dp(n + 1, inf);
	dp[src] = 0;
	set<vi> st;
	st.insert({0, src});
	vi p(n, -1);
	vector<set<int> > pars(n + 1);
	while (st.size())
	{
		auto it = st.begin();
		int u = (*it)[1];
		st.erase(it);
		for (int i = 0; i < n; i++)
		{
			int w = matrix[u][i];
			if (w == inf)
			{
				continue;
			}
			if (dp[i] > (w + dp[u]))
			{
				// deb(i);
				// deb(u);
				st.erase({dp[i], i});
				dp[i] = w + dp[u];
				pars[i].clear();
				pars[i].insert(u);
				// deb(dp[i]);
				st.insert({dp[i], i});
 
			} else if (dp[i] == (w + dp[u]))
			{
				pars[i].insert(u);
			}
		}
	}
	// for (int x : pars[dst])
	// {
	// 	cout << x << " ";
	// } cout << endl;
	if (fl)
		destroy_parents(dst, pars);
	else {
		if (dp[dst] == inf)
		{
			cout << -1 << endl;
		} else cout << dp[dst] << endl;
	}
 
 
 
}
void runcases(int T)
{
	while (1) {
 
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			return;
		}
		cin >> src >> dst;
 
		matrix.clear();
		// adj.clear()
		matrix.assign(n + 1, vi(n + 1, inf));
		for (int i = 0; i < m; i++)
		{
 
			int x, y, w;
			cin >> x >> y >> w;
			matrix[x][y] = w;
		}
//     first round for SingleSrcPath
		dij(1);
//     second round Almost SSP
		dij(0);
	}
 
 
 
 
	//cout<<"Case #"<<T<<": ";
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	// freopen("outputf.txt", "w", stdout);
#endif
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}
 
	return 0;
}
