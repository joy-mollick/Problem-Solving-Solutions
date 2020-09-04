
/// Codeforces: 723D - Lakes in Berland.
/// Category: greedy + dfs.


#include<bits/stdc++.h>

using namespace std;

struct str
{
    int x,y;
    int sz;
};

const int mx=52;

bool vis[mx][mx];
char mat[mx][mx];
bool border_area;
int conts=0;

void dfs(int x,int y,int n,int m)
{
    if(x<1 || x>n || y<1 || y>m) return;
    if(vis[x][y]) return;
    if(y==1||y==m||x==n||x==1) {border_area=true;return;}
    /// adjacent
    conts++;
    vis[x][y]=true;
    if(mat[x][y+1]=='.') dfs(x,y+1,n,m);
    if(mat[x][y-1]=='.') dfs(x,y-1,n,m);
    if(mat[x+1][y]=='.') dfs(x+1,y,n,m);
    if(mat[x-1][y]=='.') dfs(x-1,y,n,m);
}

void fill_up(int x,int y,int n,int m)
{
    if(x<1 || x>n || y<1 || y>m) return;
    if(vis[x][y]) return;
    /// adjacent
    vis[x][y]=true;
    mat[x][y]='*';
   if(mat[x][y+1]=='.') fill_up(x,y+1,n,m);
    if(mat[x][y-1]=='.') fill_up(x,y-1,n,m);
    if(mat[x+1][y]=='.') fill_up(x+1,y,n,m);
    if(mat[x-1][y]=='.') fill_up(x-1,y,n,m);
}

bool comp(str a,str b)
{
    return (a.sz<b.sz);
}

int main()
{
    int n,m,k;

    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }

    vector< str >v;
    memset(vis,false,sizeof(vis));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
    {
        if(!vis[i][j] && mat[i][j]=='.')
        {
            border_area=false;
            conts=0;
            dfs(i,j,n,m);
            if(!border_area)
            {
                str st;
                st.x=i;
                st.y=j;
                st.sz=conts;
                v.push_back(st);
            }
        }
    }

    }
    cout<<endl;
    memset(vis,false,sizeof(vis));
    sort(v.begin(),v.end(),comp);
    int siz=(int)v.size();
    siz-=k;
    int i=0;
    int x,y;
    int cells=0;
    while(siz--)
    {
        x=v[i].x;
        y=v[i].y;
        cells+=v[i].sz;
        fill_up(x,y,n,m);
        i++;
    }

    cout<<cells<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }

    return 0;
}
