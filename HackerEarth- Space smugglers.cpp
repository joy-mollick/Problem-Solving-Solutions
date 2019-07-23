#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+2;

typedef long long int ll;

typedef pair< pair<ll,ll> , pair<ll,ll> > jjj;

typedef pair<ll,ll> pii;

vector<pii>adj[mx];

vector<pii>rev_adj[mx];

ll n;


void dijkstra(ll source,ll *dist,bool*vis,vector<pii>adj[])

{
    for(int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=LONG_MAX;
    }
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(make_pair(0,source));
    dist[source]=0;
    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();
        int u =(int) p.second;
        if(vis[u]) continue;

        vis[u]=true;

        for(int i=0;i<adj[u].size();i++)
        {
            int v=(int) ( adj[u][i].first ) ;
            int weight = (int) ( adj[u][i].second ) ;

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
    ll  m;
    ll s,t,u,v,g;
    cin>>n>>m>>s>>t;
    while(m--)
    {
        cin>>u>>v>>g;
        adj[u].push_back(make_pair(v,g));
        rev_adj[v].push_back(make_pair(u,g));
    }
    bool vis[n+1];

    ll dist_s_i[n+1];
    ll dist_i_t[n+1];
    ll dist_t_i[n+1];
    ll dist_i_s[n+1];

    dijkstra(s,dist_s_i,vis,adj);
    dijkstra(t,dist_i_t,vis,rev_adj);
    dijkstra(t,dist_t_i,vis,adj);
    dijkstra(s,dist_i_s,vis,rev_adj);

    ll ans=LONG_MAX;

    ll vertex;

    for(int i=1;i<=n;i++)

    {
        if(dist_s_i[i]==LONG_MAX || dist_i_t[i]==LONG_MAX || dist_t_i[i]==LONG_MAX || dist_i_s[i]==LONG_MAX||i==s||i==t)
        {
            continue;
        }
        if(dist_s_i[i]+dist_i_t[i]+dist_t_i[i]+dist_i_s[i]<ans){
        ans=min(ans,dist_s_i[i]+dist_i_t[i]+dist_t_i[i]+dist_i_s[i]);
        }

    }

    if(ans==LONG_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }

    return 0;
}
