#include<bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

typedef pair<long,long>pii;

bool vis[mx]={false};
long dist[mx];
vector<pii>adj[mx];
priority_queue<pii,vector<pii>,greater<pii> > pq;

void dijkstra()
{
    pq.push(make_pair(0,1));
    dist[1]=0;
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
            }
        }
    }
}


int main()
{
    int n,m,f;
    cin>>n>>m>>f;
    int cap[n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>cap[i];
    }
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

        dist[i]=LONG_MAX;
    }
    dijkstra();
    vector<pii>vec;
    for(int l=1;l<=n;l++)
    {
        if(dist[l]!=LONG_MAX){
        vec.push_back(make_pair(dist[l]+f,cap[l]));} // cost , capacity
    }
    sort(vec.begin(),vec.end());
    vec.push_back(make_pair(-1,10000000));
    int i=0;
     int k;
    cin>>k;
    while(k>vec[i].second)
    {
        for(int h=0;h<vec[i].second;h++)
        {
            cout<<vec[i].first<<' ';
        }
        k=k-(vec[i].second);
        i++;
    }
    for(int y=0;y<k;y++)
    {
        cout<<(vec[i].first)<<' ';
    }
    return 0;
}
