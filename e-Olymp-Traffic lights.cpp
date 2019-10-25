#include<bits/stdc++.h>

using namespace std;


const int mx=101;
vector<int>adj[mx];
bool vis[mx];
int conn=0;
/*
void dfs(int u)
{
   vis[u]=true;
   conn++;
   vector<int>::iterator it;
   for(it=adj[u].begin();it!=adj[u].end();it++)
   {
       if(!vis[(*it)])
       {
           dfs((*it));
       }
   }
}
*/

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    //memset(vis,false,sizeof(vis));
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<adj[i].size()<<" ";
    }
    cout<<endl;
}
