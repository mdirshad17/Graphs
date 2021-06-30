// CTRL+ALT+M
// ? AtCoder Contest Question
// Tree given find
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define ff first
#define ss second
#define deb(x) cout << #x << " " << x << endl;
#define all(x) x.begin(), x.end()
#define endl "\n"
const int maxn = 1e5 + 2;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort
int color[maxn];
int visited[maxn];
vi adj[maxn];
// multiset<int> st;
map<int, int> mp;
vector<int> res;
void dfs(int s)
{
	// cout<<"HELLO\n";
	visited[s] = 1;
	if (mp[color[s]] == 0)
	{
		res.push_back(s);
	}
	mp[color[s]]++;
	for (int x : adj[s])
	{
		if (!visited[x])
			dfs(x);
	}
	// visited[s]=0;
	mp[color[s]]--;
	return;
}

void runcases(int T)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> color[i];
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);
	sort(all(res));
	for (int x : res)
	{
		cout << x << "\n";
	}
	cout << endl;

	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++)
	{
		runcases(t);
	}

	return 0;
}
