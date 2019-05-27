#include<bits/stdc++.h>

using namespace std;

void dfs(int u,bool visited[],vector<int>V[])
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=V[u].begin();it!=V[u].end();it++)
    {
        if(!visited[*it])
        {
            dfs((*it),visited,V);
        }
    }
}

int main()

{
    int n,m,k,u,v;
    cin>>n>>m>>k;
    vector<int>V[n+1];
    int sz=0;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    bool * visited=new bool [n+1];
    memset(visited,false,sizeof(visited));
    int num_of_connected=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i,visited,V);
            //cout<<i<<endl;
            num_of_connected++;
        }
    }
    if(num_of_connected>k)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<(m-n+k)<<endl;
    }
    return 0;
}
