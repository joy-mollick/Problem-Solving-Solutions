#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

vector<int>adj[51];
bool vis[51];
int depth=1;

void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            dfs(adj[u][i]);
        }
    }
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,x,y;
    cin>>n;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(vis,false,sizeof(vis));
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            sum++;
        }
    }
    long long ans= pow(2,n-sum);
    cout<<ans<<endl;
}

