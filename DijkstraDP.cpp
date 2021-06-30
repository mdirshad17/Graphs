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
const int maxn = 1e5 + 2;

void runcases(int T)
{

	int n, m, k;
	cin >> n >> m >> k;
	vpi adj[n + 2];
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	set<vi> st;
	// int dp[]/
	vector<vi> dp(n + 1, vi(k + 2, inf));
	st.insert({0, 1, 0});
	dp[1][0] = 0;
	while (st.size())
	{
		auto it = st.begin();
		int u = (*it)[1];
		int f = (*it)[2];
		st.erase(it);
		for (auto x : adj[u])
		{
			int wt = x.ss;
			int v = x.ff;
			if (dp[v][f] > (wt + dp[u][f]))
			{
				st.erase({dp[v][f], v, f});
				dp[v][f] = wt + dp[u][f];
				st.insert({dp[v][f], v, f});
			}
			if (f < k && dp[v][f + 1] > (dp[u][f]))
			{
				st.erase({dp[v][f + 1], v, f + 1});
				dp[v][f + 1] = dp[u][f];
				st.insert({dp[v][f + 1], v, f + 1});
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x = *min_element(dp[i].begin(), dp[i].end());
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
