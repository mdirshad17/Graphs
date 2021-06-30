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
#define inf 1e17
#define ff first
#define ss  second
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(x) x.begin(),x.end()
#define endl "\n"
const int maxn = 2e5 + 2;
vpi adj[maxn];
int n, m;
void dij()
{
	// set<vi> st;
	priority_queue<vi, vector<vi>, greater<vi> > st;
	vector<vector<vi> > dp(n + 1, vector<vi>(2, vi(2, inf)));
	st.push({0, 1, 0, 0});
	dp[1][0][0] = 0;
	while (st.size())
	{
		vi v = st.top();
		st.pop();
		int u = v[1];
		int f1 = v[2];
		int f2 = v[3];
		//(it);
		// deb(v[0]);
		if (dp[u][f1][f2] < v[0])
		{
			continue;
		}
		// dp[u][f1][f2] = v[0];
		for (auto x : adj[u])
		{
			int v = x.ff;
			int w = x.ss;
			if (dp[v][f1][f2] > (w + dp[u][f1][f2]))
			{
				//({dp[v][f1][f2], v, f1, f2});
				dp[v][f1][f2] = w + dp[u][f1][f2];
				st.push({dp[v][f1][f2], v, f1, f2});
			}
			if (!f1)
			{
				if (dp[v][f1 + 1][f2] > (2 * w + dp[u][f1][f2]))
				{
					//({dp[v][f1 + 1][f2], v, f1 + 1, f2});
					dp[v][f1 + 1][f2] = 2 * w + dp[u][f1][f2];
					st.push({dp[v][f1 + 1][f2], v, f1 + 1, f2});
				}
			}
			if (!f2)
			{
				if (dp[v][f1][f2 + 1] > ( dp[u][f1][f2]))
				{
					//({dp[v][f1][f2 + 1], v, f1, f2 + 1});
					dp[v][f1][f2 + 1] = dp[u][f1][f2];
					st.push({dp[v][f1][f2 + 1], v, f1, f2 + 1});
				}
			}
			if (!f1 && !f2)
			{
				if (dp[v][f1 + 1][f2 + 1] > (w + dp[u][f1][f2]))
				{
					//({dp[v][f1 + 1][f2 + 1], v, f1 + 1, f2 + 1});
					dp[v][f1 + 1][f2 + 1] = w + dp[u][f1][f2];
					st.push({dp[v][f1 + 1][f2 + 1], v, f1 + 1, f2 + 1});
				}
			}



		}

	}
	for (int i = 2; i <= n; i++)
	{
		cout << dp[i][1][1] << " ";
	} cout << endl;





}
void runcases(int T)
{
	cin >> n >> m;
	// adj.resize(n + 2);
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	dij();

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
