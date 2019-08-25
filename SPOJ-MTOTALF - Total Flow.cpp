#include<bits/stdc++.h>

using namespace std;

const int mx=129;
typedef unsigned long long int ll;

ll resgraph[mx][mx];
int parent[mx];

ll mx_flow=0;

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
        for(int v=0;v<129;v++)
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
    memset(resgraph,0,sizeof(resgraph));
    int m,v,u,n;
    char a,b;
    ll c;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        resgraph[(int)a][(int)b]+=c;
    }
    char s,t;
    s='A';
    t='Z';
    fordFulker((int)s,(int)t);
    cout<<mx_flow<<'\n';
}
