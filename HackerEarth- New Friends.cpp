#include<bits/stdc++.h>

using namespace std;

int graph[153][153]={0};
int resgraph[153][153]={0};
int parent[153];

int mx_flow=0;

bool bfs(int s,int t)
{
    bool visited[153]={false};
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<153;v++)
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
    for(int u=0;u<153;u++)
    {
        for(int v=0;v<153;v++)
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
        mx_flow=mx_flow+path_flow;
    }
}

int main()

{
    int test,V,total;
    cin>>test;
    while(test--){
    cin>>V>>total;
    int u,v,k;
    int cst;
    int source,sink;
    while(total--)
    {
    cin>>u>>v;
    graph[u][v]=1;
    }
    cin>>source>>sink>>k;
    fordFulker(source,sink);
    if(mx_flow>=k+1)// with k friends , they are totally k+1 friends
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    mx_flow=0;
    memset(graph,0,sizeof(graph));
    memset(resgraph,0,sizeof(resgraph));
    }
    return 0;
}
