#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
int mat[6][6]={
{1,1,0,1,1,1},
{1,0,1,1,0,1},
{1,0,1,1,0,0},
{1,1,1,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0}};
// In the queue of bfs we will store a node
struct points
{
	int x;
	int y;
	points(int a,int b)
	{
		this->x=a;
		this->y=b;
	}
};
bool valid(int x,int y)
{
	return (x>=0) && (x<6) && (y>=0) && (y<6) && (mat[x][y]==1);
}
int BFS(points *src,points *dst)
{
	queue<points*> q;
	if((src->x==dst->x) && (src->y==dst->y))
	{
		return 0;
	}
	if(mat[src->x][src->y]==0)
	{
		return -1;
	}
	int l=0;
	mat[src->x][src->y]=0;
	q.push(src);
	int xdir[]={-1,1,0,0};
	int ydir[]={0,0,-1,1};
	while(!q.empty())
	{
		int n=q.size();
		while(n--)
		{
			points* P=q.front();
			q.pop();
			int x=P->x;
			int y=P->y;
			
			 cout<<x<<" "<<y<<endl;
		     if((dst->x==x) && (dst->y==y))
		     {
		     	return l;
		     }
		     for(int i=0;i<4;i++)
		     {
              if(valid(x+xdir[i],y+ydir[i]))
			  {

			  	// Marking that this cell has been visited
			  	// We could have used  a  2D visited array
			  	// here we have optimised the space complexity
			  	 mat[x+xdir[i]][y+ydir[i]]=0;
                 points * d=new points(x+xdir[i],y+ydir[i]);
              
              q.push(d);
			  }
		     }	

		}cout<<endl;l++;
	}
	return -1;
}
void runcases(int T)
{

// We will have a matrix given the cords of src and dest 
// every matrix element represents 0 or 1 
// 0 means unsafe and 1 means safe we have to return the shortest path length
// shortest path we need BFS
	points *src=new points(0,0);
	points *dst=new points(1,5);

 	cout<<BFS(src,dst);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T = 1;
    //cin >> T;
    for (int t=1;t<=T; t++) {
        runcases(t);
    }

    return 0;
}
