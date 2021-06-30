/*
Given a 2D matrix return the number of connected components
*/
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef vector<int> vi;
typedef pair<int, int> pii;
int mat[6][6] = {
  {1, 0, 1, 1, 1, 1},
  {1, 0, 1, 1, 0, 1},
  {1, 1, 1, 0, 0, 1},
  {0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 0},
  {0, 0, 1, 0, 0, 0}
};
void DFS(int x, int y)
{

  int xdir[] = { -1, 1, 0, 0};
  int ydir[] = {0, 0, -1, 1};
  if (x<0 or y<0 or x >= 6 or y >= 6 or mat[x][y] == 1)
  {
    return;
  }
  // cout<<x<<" "<<y<<endl;
  mat[x][y] = 1;
  // 2d matrix visited;
  for (int i = 0; i < 4; i++)
  {
    DFS(x + xdir[i], y + ydir[i]);
  }
}
void runcases(int T)
{

  // converting all 0 to -1
  int ans = 0;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (mat[i][j] == 0)
      {
        DFS(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  // for(int i=0;i<6;i++)
  // {
  //  for(int j=0;j<6;j++)
  //  {
  //    cout<<mat[i][j]<<" ";
  //  }cout<<endl;
  // }



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
