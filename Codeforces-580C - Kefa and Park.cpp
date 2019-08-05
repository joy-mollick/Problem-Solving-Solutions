#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;
typedef pair<int,int> pi;
vector<int>adj[mx];
bool vis[mx];
int cat[mx];
int n,m;
int ans=0;
int parent[mx]={-1};
int dp[mx]={0};
int mx_consecutive[mx]={0};

void dfs(int u,int prev)
{
    vis[u]=true;
    if(cat[u])
    {
        dp[u]=1+dp[prev];
    }
    else{
        dp[u]=0;
    }
    mx_consecutive[u]=max(mx_consecutive[prev],dp[u]);
    bool is_leaf=true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!vis[v] && v!=prev)
        {
             parent[v]=u;
            dfs(v,u);
            is_leaf=false;
        }
    }
    if(mx_consecutive[u]<=m &&is_leaf )
        ans++;
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>cat[i];
    }
    for(int j=1;j<=n-1;j++)
    {
        cin>>u>>v;
        adj[u].push_back((v));
        adj[v].push_back((u));
    }
    memset(vis,false,sizeof(vis));
    dfs(1,-1);
    cout<<ans<<'\n';
}

