#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;
const unsigned long long int md=1e18;
typedef pair<unsigned long long int,int> pii;
vector< pair<int,unsigned long long int> >adj[mx];
unsigned long long int dist1[mx];
bool vis[mx];
int parent[mx];

void djkstra(int source,unsigned long long int *dist)

{
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(make_pair(0,source));
    dist[source]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]==true) continue;

        vis[u]=false;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int weight = adj[u][i].second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
                parent[v]=u;
            }
        }
    }

}


int main()

{
    int n,m,a,b;
    unsigned long long int w;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    for(int i=1;i<=n;i++)
    {
        dist1[i]=md;
        vis[i]=false;
        parent[i]=i;
    }
    djkstra(1,dist1);
    if(dist1[n]==md)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    vector<int>v;
    int u=n;
    while(parent[u]!=u)
    {
         v.push_back(u);
        u =parent[u];
    }
    v.push_back(1);
    vector<int>::reverse_iterator it;
    for(it=v.rbegin();it!=v.rend();it++)
    {
        cout<<" "<<(*it);
    }
    cout<<endl;
}
