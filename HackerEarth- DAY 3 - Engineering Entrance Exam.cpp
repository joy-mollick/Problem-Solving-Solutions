#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

typedef pair<long,long>pii;

bool vis[mx]={false};
long dist[mx];
vector<pii>adj[mx];
priority_queue<pii,vector<pii>,greater<pii> > pq;

void dijkstra()
{

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u])
        continue;

        vis[u]=true;
        vector<pii>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            int weight =(*it).second;
            //cout<<v<<" "<<dist[v]<<" "<<(dist[u]+weight)<<endl;
            if( (dist[v]>dist[u]+weight))
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
                //cout<<dist[v]<<endl;
            }
        }
    }
}


int main()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    int u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int x;
     for(int i=1;i<=n;i++)
    {

        dist[i]=1000000007;
    }
    while(k--)
    {
        cin>>x;
        pq.push(make_pair(0,x)); // exma centres
        dist[x]=0;
    }
    dijkstra();
    while(q--)
    {
        cin>>x;
        if(dist[x]==1000000007)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<dist[x]<<endl;
        }
    }
    return 0;
}
