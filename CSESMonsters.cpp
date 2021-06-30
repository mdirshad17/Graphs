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
vector<vc> grid;
vector<vi> matrix;
vector<vi> visited;
int n, m;

bool good(int s, int e)
{
	if (s<0 or s >= n or e<0 or e >= m || visited[s][e])
	{
		return 0;
	}
	return 1;
}
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs(int s, int e)
{
	queue<vi> q;
	q.push({s, e});
	visited[s][e] = 1;
	int l = 0;
	while (!q.empty())
	{
		int sz = q.size();
		while (sz--)
		{
			vi d = q.front();
			q.pop();
			if
			for (int i = 0; i < 4; i++)
				{

				}

		}
	}
}
void runcases(int T)
{

	cin >> n >> m;
	grid.resize(n, vc(m));
	matrix.assign(n, vi(m, inf));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (grid[i][0] == '.')
		{
			grid[i][0] = 'F';
		}
		if (grid[i][m - 1] == '.')
		{
			grid[i][m - 1] = 'F';
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (grid[0][i] == '.')
		{
			grid[0][i] = 'F';
		}
		if (grid[n - 1][i] == '.')
		{
			grid[n - 1][i] = 'F';
		}
	}

	visited.assign(n, vi(m, inf));


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
