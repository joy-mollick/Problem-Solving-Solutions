/// Time-  0.007s
/// LightOj- 1066 - Gathering Food 
/// BFS + brute force 

#include<bits/stdc++.h>

using namespace std;

const int siz=13;

int n;

string grid[siz];
int dist[siz][siz];
bool vis[siz][siz];
char dest;
int src_x,src_y;

/// move side
 int dx[]={1,-1,0,0};
 int dy[]={0,0,1,-1};

 void initia()
 {
     for(int i=0;i<siz;i++)
     {
         for(int j=0;j<siz;j++)
         {
             vis[i][j]=false;
             dist[i][j]=INT_MAX;
         }
     }
 }

 int BFS(int srcx,int srcy)
 {
     initia();
     queue<pair<int,int>>Q;
     Q.push(make_pair(srcx,srcy));
     vis[srcx][srcy]=true;
     dist[srcx][srcy]=0;
     int srcxx,srcyy,destxx,destyy;
     while(!Q.empty())
     {
         pair<int,int> p=Q.front();
         Q.pop();
         srcxx=p.first;
         srcyy=p.second;

         if(grid[srcxx][srcyy]==dest)
         {
             /// get new source's x and y .
             src_x=srcxx;
             src_y=srcyy;

             return dist[srcxx][srcyy];
         }

         for(int i=0;i<4;i++)
         {
             destxx=srcxx+dx[i];
             destyy=srcyy+dy[i];

             if(destxx>=0 && destxx<n && destyy>=0 && destyy<n && vis[destxx][destyy]==0)
             {
                 if( (grid[destxx][destyy]>dest && dest<='Z') || (grid[destxx][destyy]=='#') )
                 {
                     continue;
                 }

                 vis[destxx][destyy]=true;
                 dist[destxx][destyy]=dist[srcxx][srcyy]+1;
                 Q.push(make_pair(destxx,destyy));
             }
         }
     }
      return -1;
 }


int main()

{
    int T,w;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
       scanf("%d",&n);
       for(int i=0;i<n;i++)
       {
           cin>>grid[i];
       }
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               /// finding first charcater
               if(grid[i][j]=='A') {src_x=i,src_y=j;}
               /// how many characters ?
               if(isupper(grid[i][j])) cnt++;
           }
       }
       int cost=0,res=0;
       /// when source is A then destination is B
       dest='B';
       printf("Case %d: ",caso);
       cnt--;

       for(int i=0;i<cnt;i++)
       {
           /// every time ,get new sourcex and sourcey
           cost=BFS(src_x,src_y);
           if(cost==-1)
           {
               puts("Impossible");
               break;
           }
           else res+=cost;
           /// destination changed
           dest++;
       }
       if(cost!=-1) printf("%d\n",res);
    }
    return 0;
}
