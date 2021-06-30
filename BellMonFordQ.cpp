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
int n, m;
vector<vi> adj;
vi Bel_Ford()
{
	vi d(n + 1, 0);
	for (int i = 0; i < 2 * n; i++)
	{
		// vi d = d;
		for (auto x : adj)
		{
			int u = x[0];
			int v = x[1];
			int w = x[2];
			if (i < n - 1)
			{
				d[v] = min(d[v], d[u] + w);
			} else
			{
				if (d[v] > (w + d[u]))
				{
					d[v] = -inf;
				}
			}
		}


	}
	return d;
}

void runcases(int T)
{
	cin >> n >> m;
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj.push_back({x, y, w});
	}
	vi d = Bel_Ford();
	for (auto &x : adj)
	{	swap(x[0], x[1]);

	}
	vi d1 = Bel_Ford();
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == -inf || d1[i] == -inf)
		{
			cout << "INF\n";
		} else
		{
			cout << (d[i] + d1[i]) << endl;
		}
	}




	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}

/*
1
7 7
1 3 2
5 1 -4
2 5 3
2 6 2
3 5 1
4 6 -3
7 4 -3


*/