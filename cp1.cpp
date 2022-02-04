#include <bits/stdc++.h>
using namespace std;
#define      int long long int
#define      M    1000000007
#define      hM   9999999900000001
#define      vi vector<int>
#define      vvi vector<vi>
#define      vpi vector<pair<int,int>>
#define      pii pair<int,int>
#define      pb push_back
#define      inf 1e18
#define      ff first
#define      forn(i, n) for (int i = 0; i < n; i++)
#define      ss  second
#define      line  "\n"
#define      deb(x) cout<<#x<<" "<<x<<endl;
#define      all(x) x.begin(),x.end()
#define      printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
const int N = 1e5 + 5, lg = 20;

//int BIT[N];
//void add(int x, int val) {while (x < N)BIT[x] += val, x += x & -x;}
//int sum(int x) {return x ? BIT[x] + sum(x - (x & -x)) : 0;}

vpi adj[N];
void runcases(int T)
{   int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
    }
    priority_queue<pii, vpi, greater<pii>> pq;// holding multiple instances
    int dp[n + 1][k];
    memset(dp, 10, sizeof(dp));
    dp[1][0] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        pii tp = pq.top();
        pq.pop();
        int u = tp.second;
        int d = tp.first;
        if (dp[u][k - 1] < d)continue;
        for (auto x : adj[u]) {
            int nb = x.ff;
            int wt = x.ss;
            if (dp[nb][k - 1] > wt + d) {
                dp[nb][k - 1] = wt + d;
                pq.push({dp[nb][k - 1], nb});
                sort(dp[nb], dp[nb] + k);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << dp[n][i] << " ";
    } cout << "\n";






    //cout << "Case #" << T << ": ";
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

