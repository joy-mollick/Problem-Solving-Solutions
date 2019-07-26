// Bicolouring problem , slightly modified

#include<bits/stdc++.h>

using namespace std;

const int mx=401;

typedef pair<int,int>pii;
vector<pii>rail[mx];
vector<pii>bus[mx];
set<pii>s;
int dist_rail[mx];
int dist_bus[mx];
bool vis[mx];

void djkstra(vector<pii>adj[],int *dist)

{
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(make_pair(0,1));
    dist[1]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;

        vis[u]=true;
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
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        rail[a].push_back(make_pair(b,1));
        rail[b].push_back(make_pair(a,1));
        s.insert(make_pair(min(a,b),max(a,b)));
    }
    for(int i=1;i<=n;i++)
    {
        dist_rail[i]=INT_MAX;
        dist_bus[i]=INT_MAX;
        vis[i]=false;
    }
    djkstra(rail,dist_rail);
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            pii p;
            p.first=i;
            p.second=j;
            if(!s.count(p))
            {
                bus[i].push_back(make_pair(j,1));
                bus[j].push_back(make_pair(i,1));
            }
        }
    }
    djkstra(bus,dist_bus);
    if(dist_bus[n]==INT_MAX||dist_rail[n]==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else{
        cout<<max(dist_bus[n],dist_rail[n])<<endl;
    }
}
