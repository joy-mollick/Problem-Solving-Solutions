#include<bits/stdc++.h>

using namespace std;

const int mx=206;
typedef unsigned long long int ll;

ll resgraph[mx][mx];
int parent[mx];

ll mx_flow=0;
int n;

bool bfs(int s,int t)
{
    bool visited[mx]={false};
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(visited[v]==false && resgraph[u][v]>0)
            {
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t]==true);
}

void fordFulker(int s,int t)
{
    int v;
    while(bfs(s,t)==true)
    {
        ll path_flow=INT_MAX;
        for(v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            path_flow=min(path_flow,resgraph[u][v]);
        }
        for(v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            resgraph[u][v]-=path_flow;
            resgraph[v][u]+=path_flow;
        }
        //cout<<path_flow<<endl;
        mx_flow=mx_flow+path_flow;
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,a;
    cin>>t;
    while(t--){
    memset(resgraph,0,sizeof(resgraph));
    memset(parent,0,sizeof(parent));
    mx_flow=0;
    int m,v,u;
    ll c;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {

        cin>>a;
        for(int j=1;j<=a;j++)
        {
            cin>>c;
            if(i==1||c==n) resgraph[i][c]=1;
            else resgraph[i][c]=10000;
        }
    }
    fordFulker(1,n);
    cout<<mx_flow<<endl;
    }
}
