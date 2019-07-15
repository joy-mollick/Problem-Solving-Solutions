#include<bits/stdc++.h>

using namespace std;

bool visited[100]={false};
vector<int>adj[25];
stack<int>s;

void dfs(int u)
{
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visited[adj[u][i]])
        {
            dfs(adj[u][i]);
        }
    }
    s.push(u);
}

int main()

{
    int V,e,u,v;
    cin>>V>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int j=0;j<25;j++)
    {
        int sz=adj[j].size();
        if(sz>0)
        {
            sort(adj[j].begin(),adj[j].end(),greater<int>());// decreasing order
        }
    }
    for(int k=V;k>0;k--)
    {
        if(!visited[k])
        {
            dfs(k);
        }
    }
    int count=0;
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        count++;
        if(count==1)
        {
            cout<<val;
        }
        else
        {
            cout<<" "<<val;
        }

    }
    cout<<endl;
    return 0;
}
