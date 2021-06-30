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
#define inf 1e15
#define ff first
#define ss  second
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(x) x.begin(),x.end()
#define endl "\n"
const int maxn = 1e5;
vector<vi> adj;
int n, m;
void BelFord()
{
	vi d(n + 1, -inf);
	d[1] = 0;
	for (int i = 0; i < n + 2; i++)
	{
		for (auto x : adj)
		{

			int u = x[0], v = x[1], w = x[2];
			if (i <= n - 1) {
				d[v] = max(d[v], w + d[u]);
			} else
			{
				if (d[v] < (w + d[u]))
				{
					d[v] = inf;
				}
			}
		}
	}
	if (d[n] >= inf)
	{
		cout << -1 << endl;
		return;
	}
	cout << d[n] << endl;
}
void runcases(int T)
{
	adj.clear();

	cin >> n >> m;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		adj.pb({u, v, w});
	}

	BelFord();




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
