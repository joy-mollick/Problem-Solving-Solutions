#include<bits/stdc++.h>

using namespace std;

const int mx=10001;

typedef pair<int,int> pi;
const int inf=1e9;
vector<pi>adj[mx];
vector<pi>rev_adj[mx];
int dist[mx];
int dist2[mx];
bool vis[mx];

void djkstra(int src)
{
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    memset(vis,false,sizeof(vis));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]==false) vis[u]=true;
        else continue;
        vector<pi>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            int weight=(*it).second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}
void djkstra2(int src)
{
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    pq.push(make_pair(0,src));
     memset(vis,false,sizeof(vis));
    dist2[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]==false) vis[u]=true;
        else continue;
        vector<pi>::iterator it;
        for(it=rev_adj[u].begin();it!=rev_adj[u].end();it++)
        {
            int v=(*it).first;
            int weight=(*it).second;
            if(dist2[v]>dist2[u]+weight)
            {
                dist2[v]=dist2[u]+weight;
                pq.push(make_pair(dist2[v],v));
            }
        }
    }
}

int main()

{

    int tc,n,m,k,s,t,a,b,c;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m>>k>>s>>t;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            rev_adj[i].clear();
            dist[i]=inf;dist2[i]=inf;
        }
        while(m--)
        {
            cin>>a>>b>>c;
            adj[a].push_back(make_pair(b,c));
            rev_adj[b].push_back(make_pair(a,c));
        }
        djkstra(s);
        djkstra2(t);
        int ans=dist[t];
        //cout<<ans<<endl;
        while(k--)
        {
            cin>>a>>b>>c;
            //cout<<dist[a]<<" "<<dist2[b]<<endl;
            ans=min(ans,min((dist[a]+dist2[b]+c),dist[b]+dist2[a]+c));
        }
        if(ans!=inf)
        cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
