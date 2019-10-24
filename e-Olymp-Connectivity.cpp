#include<bits/stdc++.h>

using namespace std;


const int mx=101;
vector<int>graph[mx];
bool vis[mx];

void dfs(int u)
{
    vis[u]=true;
    vector<int>::iterator it;
    for(it=graph[u].begin();it!=graph[u].end();it++)
    {
        if(!vis[(*it)])
        {
            dfs((*it));
        }
    }
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    while(m--)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    bool disco=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) disco=true;
    }
    if(disco) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
