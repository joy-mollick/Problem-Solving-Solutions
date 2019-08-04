#include<bits/stdc++.h>

using namespace std;

typedef pair<int,char> pi;

bool vis[51][51];
char graph[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m,n;
bool ok=false;

void dfs(int i,int j,int frmi,int frmj,char co)
{
    if(i<1||j<1||i>m||j>n) return;

    if(graph[i][j]!=co) return;

    if(vis[i][j]) {ok=true; return ;}

    vis[i][j]=true;

    for(int y=0;y<4;y++)
    {
        int nxti=i+dx[y];
        int nxtj=j+dy[y];

        if(nxti==frmi && nxtj==frmj)
            continue;// it doesn't go back from where it comes from

         dfs(nxti,nxtj,i,j,co);
    }
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(vis,false,sizeof(vis));
    int x,y,u,v;
    char c;
    cin>>m>>n;
    for(int i=1;i<=m;i++)

    {
        for(int j=1;j<=n;j++)

        {
            cin>>graph[i][j];
        }
    }
    for(int i=1;i<=m;i++)
    {
       for(int j=1;j<=n;j++)
       {
           char z=graph[i][j];
           //cout<<z<<endl;
           if(!vis[i][j])
           {
               dfs(i,j,-1,-1,z);
               if(ok)
               {
                   cout<<"Yes"<<endl;
                  return 0;
               }
           }
       }
    }
    cout<<"No"<<endl;
}

