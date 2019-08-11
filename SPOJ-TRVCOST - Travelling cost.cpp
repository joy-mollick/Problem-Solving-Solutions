#include<bits/stdc++.h>

using namespace std;


const int mx=505;

typedef pair<int,int> pi;

vector<pi>adj[mx];

bool vis[mx];
int dist[mx];

int n,mxi;

void djkstra(int source)
{
    for(int j=0;j<mx;j++) {dist[j]=INT_MAX;vis[j]=false;}

    priority_queue<pi,vector<pi>,greater<pi> >pq;
    pq.push(make_pair(0,source));
    dist[source]=0;
    while(!pq.empty())
    {
        pi p=pq.top();
        pq.pop();
        int u=p.second;
        if(vis[u]) continue;

        else vis[u]=true;

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int graph[mx][mx];
    for(int i=0;i<mx;i++)
    {
        for(int j=0;j<mx;j++)
        {
            if(i!=j)
            {
                graph[i][j]=INT_MAX;
            }
        }
    }
    int a,b,w,source,q,dest;
    int mxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>w;
        mxi=max(a,mxi);
        mxi=max(b,mxi);
        graph[a][b]=min(graph[a][b],w);
        graph[b][a]=min(w,graph[b][a]);
    }
    for(int i=0;i<mx;i++)
    {
        for(int j=0;j<mx;j++)
        {
            if(graph[i][j]!=INT_MAX&&i!=j)
            {
                adj[i].push_back(make_pair(j,graph[i][j]));
                adj[j].push_back(make_pair(i,graph[i][j]));
            }
        }
    }
    cin>>source;
    djkstra(source);
    cin>>q;
    while(q--)
    {
        cin>>dest;
        if(vis[dest]==false)
        {
            cout<<"NO PATH"<<'\n';
        }
        else{
            cout<<dist[dest]<<'\n';
        }
    }
    return 0;
}
