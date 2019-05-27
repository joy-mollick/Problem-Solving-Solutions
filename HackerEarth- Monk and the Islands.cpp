#include<bits/stdc++.h>

using namespace std;
const int mn=1e5+1;
long int dist[mn];
bool visited[mn];
void bfs(int s,int d,vector<int>v[])
{
    visited[1]=true;
    queue<int>q;
    dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int it=0;it<v[u].size();it++)
        {

            if(visited[v[u][it]]==false)
            {
                visited[v[u][it]]=true;
                dist[v[u][it]]=dist[u]+1;
                q.push(v[u][it]);
            }
        }
    }
}

int main()

{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int>v[n+1];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=0;i<=n;i++)
        {
            dist[i]=0;
            visited[i]=false;
        }
        bfs(1,n,v);
        cout<<dist[n]<<endl;
    }
    return 0;
}
