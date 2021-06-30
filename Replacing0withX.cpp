/*
Given a matrix we can convert a streak of  zeros into 1 if all the 0
are surrouded by 1
****************
{
{1,1,1},
{1,0,1},
{1,0,1},
{1,1,1}
}
OUTPUT
{
{1,1,1},
{1,1,1},
{1,1,1},
{1,1,1}
}
********************
{
{1,1,1},
{1,0,1},
{1,0,1},
{1,0,1}
}
OUTPUT
{
{1,1,1,1,1},
{1,-1,1,0,1},
{1,-1,1,0,1},
{1,-1,1,1,1}
}
**********************
In th second case we were not able to convert the 0 to 1 cause the
last row zero was not covered by ones in all direction
so for the second row 0 this is open in one side
for the 1st row it is also open
*** we can convert only those which are covered by one on all the 4 directions
*/
/*
1.observation to be made  streak of 0  represents here connected components
2.We can convert only those connected components to 1 if they are covered by 1's on all the sides
3.Those which are not convertible to the 1's are those components which have atleast one zero at the boundary

#steps
1.convert all zeros to -1
2.Traverse for all the boundary elements if that element is -1 the do DFS mark all the connected components to 0
3.After this there is still -1 present then convert it to 1
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
  if (x<0 or y<0 or x >= 6 or y >= 6 or mat[x][y] != -1)
  {
    return;
  }
  // cout<<x<<" "<<y<<endl;
  mat[x][y] = 0;
  for (int i = 0; i < 4; i++)
  {
    DFS(x + xdir[i], y + ydir[i]);
  }
}
void runcases(int T)
{

  // converting all 0 to -1
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (mat[i][j] == 0)
      {
        mat[i][j] = -1;
      }
    }
  }
  // for(int i=0;i<6;i++)
  // {
  //  for(int j=0;j<6;j++)
  //  {
  //    cout<<mat[i][j]<<" ";
  //  }cout<<endl;
  // }
  for (int i = 0; i < 6; i++)
  {



    if (mat[0][i] == -1)
    {
      DFS(0, i);
    }
    if (mat[5][i] == -1)
    {
      DFS(5, i);
    }
    if (mat[i][0] == -1)
    {
      DFS(i, 0);
    }
    if (mat[i][5] == -1)
    {
      DFS(i, 5);
    }
  }
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      (mat[i][j] == -1 ? (mat[i][j] = 1) : mat[i][j] = mat[i][j]);
    }
  }
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      cout << mat[i][j] << " ";
    } cout << endl;
  }


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
