#include<bits/stdc++.h>

using namespace std;
const int mx=1e5+1;
 bool visited[mx];
void dfs(int u,vector<int>v[])
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=v[u].begin();it!=v[u].end();it++)
    {
        if(!visited[(*it)])
        {
            dfs((*it),v);
        }
    }
}

int main()
{
    int n,m,u,t,head;
    cin>>n>>m;
    vector<int>v[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>t;
        v[u].push_back(t);
        v[t].push_back(u);
    }
    cin>>head;
    memset(visited,false,sizeof(visited));
    dfs(head,v);
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
