
/// Time - 0.009s
/// Codeforces 1130C - Connect 
/// Greedy + Flood Fill.


/// It can be done by dfs also 

#include<bits/stdc++.h>

using namespace std;

int nm;

int vis[51][51];
char grid[51][51];

/// up - down - right - left
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void BFS(int src_x,int src_y,int val)
{
   queue<pair<int,int> >q;
   vis[src_x][src_y]=val; /// consider it as vampire and color it as BLACK
   q.push(make_pair(src_x,src_y));

   while(!q.empty())
   {
       int x=q.front().first;
       int y=q.front().second;
       q.pop();

       for(int i=0;i<4;i++)
       {
          int xx=x+dx[i];
          int yy=y+dy[i];
          if(xx>=0 && yy>=0 && xx<nm && yy<nm && grid[xx][yy]=='0' && vis[xx][yy]==0 )
          {
              vis[xx][yy]=val;
              q.push(make_pair(xx,yy));
          }
       }
   }
}

int dist(int x,int y,int xx,int yy)
{
    return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}

int main()

{
      memset(vis,0,sizeof(vis));
      cin>>nm;
      int src_x,src_y,dst_x,dst_y;
      cin>>src_x>>src_y>>dst_x>>dst_y;
      src_x--;src_y--;dst_x--;dst_y--;
      for(int i=0;i<nm;i++)
      {
          for(int j=0;j<nm;j++)
          {
              cin>>grid[i][j];
          }
      }

      BFS(src_x,src_y,1);
      if(vis[dst_x][dst_y]==1)
      {
          cout<<"0"<<endl;
          return 0;
      }

      int ans=INT_MAX;
      BFS(dst_x,dst_y,2);
      for(int i=0;i<nm;i++)
      {
          for(int j=0;j<nm;j++)
          {
              if(vis[i][j]==1 && grid[i][j]=='0')
              {
                  for(int m=0;m<nm;m++)
                  {
                      for(int n=0;n<nm;n++)
                      {
                          if(vis[m][n]== 2 && grid[m][n]=='0')
                          {
                              ans=min(ans,dist(i,j,m,n));
                          }
                      }
                  }
              }
          }
      }

      cout<<ans<<endl;
}
