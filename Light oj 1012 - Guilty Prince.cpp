
/// Time - 0.009s
/// Light oj 1012 - Guilty Prince 
/// Graph theory + Flood Fill.


/// It can be done by dfs 

#include<bits/stdc++.h>

using namespace std;

int col,row;

char grid[21][21];
int vis[21][21];

/// up - down - right - left
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int ans;


void BFS(int src_x,int src_y)
{
   queue<pair<int,int> >q;
   vis[src_x][src_y]=1; /// consider it as vampire and color it as BLACK
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

          if(xx>=0 && yy>=0 && xx<col && yy<row &&grid[xx][yy]!='#' && vis[xx][yy]!=1)
          {
              vis[xx][yy]=1;
              ans++;
              q.push(make_pair(xx,yy));
          }
       }
   }

}

int main()

{
    int T,n,u,v;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {

       memset(vis,0,sizeof(vis));
       ans=1;
       int src_x,src_y;
       cin>>row>>col;
       for(int i=0;i<col;i++)
       {
           for(int j=0;j<row;j++)
           {
               cin>>grid[i][j];

               if(grid[i][j]=='@')
               {
                   src_x=i;
                   src_y=j;
               }
           }
       }
       BFS(src_x,src_y);
       printf("Case %d: %d\n",caso,ans);

    }
    return 0;
}
