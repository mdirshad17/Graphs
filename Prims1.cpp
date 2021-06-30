// // CTRL+ALT+M 
// #include <bits/stdc++.h>
// using namespace std;
// #define M 1000000007
// #define int long long int
// #define vi vector<int> 
// #define vb vector<bool>
// #define vc vector<char>
// #define vpi vector<pair<int,int>>
// #define pii pair<int,int>
// #define pb push_back
// #define inf 1e18
// #define ff first
// #define ss  second
// #define deb(x) cout<<#x<<" "<<x<<endl;
// #define all(x) x.begin(),x.end()
// #define endl "\n"
// const int maxn=1e5;
// //*! look for binary search see if dp can fit or dp with bs 
// //*? Set or Priority_queue
// //*! Number is upto 10^5 check if a[maxn] gives something
// //*? Graph Question depedencies Topo sort
// //todo For a Tree its shortest Path in  dfs is same as in bfs if it is acyclic
// // *! Bridge Detection:: From Backedge we take low[u]=min(low[u],tin[x]) 
// // *! Bridge Detection:: From Child we take low[u]=min(low[u],low[x]) 
// // *! Bridge Detection:: this is a bridge if(low[x]>tin[u]) 
// vpi adj[maxn];
// int visited[maxn];
// void Prims(int n)
// {
//     int wt[n];
//     int par[n];
//     set<pii> st;
//     vi visited(n,0);
//     wt[0]=0;
//     st.insert({0,0});
//     while(!st.empty())
//     {
//         pii top=*(st.begin());
//         st.erase(st.begin());
    
//         int u=top.ss;
//         int w=top.ff;
//         visited[u]=1;
//         for(auto x:adj[u])
//         {
//             if()
//         }
//     }
// }
// void runcases(int T)
// {

//   int n,m;
//   cin>>n>>m;
//   for(int i=0;i<m;i++)
//   {
//       int x,y,w;
//       cin>>x>>y>>w;
//       adj[x].pb({y,w});
//       adj[y].pb({x,w});
//   }
//   Prims(n);


  

//   //cout<<"Case #"<<T<<": ";
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int T = 1;
//     //cin >> T;
//     for (int t=1;t<=T; t++) {
//         runcases(t);
//     }

//     return 0;
// }
