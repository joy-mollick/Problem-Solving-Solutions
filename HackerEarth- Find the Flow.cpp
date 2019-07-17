#include<bits/stdc++.h>

using namespace std;

int graph[91][91]={0};
int resgraph[91][91]={0};
int parent[91];

int mx_flow=0;

bool bfs(int s,int t)
{
    bool visited[91]={false};
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<91;v++)
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
    for(int u=0;u<91;u++)
    {
        for(int v=0;v<91;v++)
        {
            resgraph[u][v]=graph[u][v];
        }
    }
    while(bfs(s,t)==true)
    {
        int path_flow=INT_MAX;
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
    int total;
    cin>>total;
    char a,b;
    int cst;
    int source,sink;
    char c1,c2;
    c1='S';
    c2='T';
    source=(int)c1;
    sink=(int)c2;
    while(total--)
    {
    cin>>a>>b>>cst;
    int u=(int)a;
    int v=(int)b;
    graph[u][v]=cst;
    }
    fordFulker(source,sink);
    cout<<mx_flow<<endl;
    return 0;
}
