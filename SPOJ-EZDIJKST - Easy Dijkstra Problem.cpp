#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

const int mx=1e4+1;
const int INF=INT_MAX;

vector<pi>v[mx];
bool vis[mx];
int dist[mx];

void djkstra(int source)
{
    priority_queue<pi,vector<pi>,greater<pi> >pq;
    pq.push(make_pair(0,source));
    dist[source]=0;
    while(!pq.empty())
    {
        pi p=pq.top();
        int u=p.second;
        pq.pop();
        if(vis[u]) {continue;}
        vis[u]=true;
        for(int i=0;i<v[u].size();i++)
        {
            int V=v[u][i].first;
            int weight=v[u][i].second;
            if(dist[V]>dist[u]+weight)
            {
                dist[V]=dist[u]+weight;
                pq.push(make_pair(dist[V],V));
            }
        }
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(vis,false,sizeof(vis));
    int tc,n,m,a,b,c,source,desti;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            vis[i]=false;
            dist[i]=INF;
            v[i].clear();
        }
        while(m--)
        {
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b,c));
        }
        cin>>source>>desti;
        djkstra(source);
        if(vis[desti])
        cout<<dist[desti]<<'\n';

        else cout<<"NO"<<'\n';
    }
}
