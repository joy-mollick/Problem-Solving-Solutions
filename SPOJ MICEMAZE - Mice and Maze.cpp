#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ipair;

const int mx=1e4+1;

vector<ipair>adj[mx];

map<string,int>m;

vector<int>dist(mx);

#define inf 1e7

int n;

void shortest_path(int src)
{
    priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
    bool vis[n+1]={false};
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(!vis[u]) vis[u]=true;
        else continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(weight+dist[u]<dist[v])
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

int main()

{
    int tc,c,x,w,b,M,src,tme,a;
        cin>>n;
        cin>>src;
        cin>>tme;
        cin>>M;

        while(M--)
        {
            cin>>a>>b>>x;
            adj[b].push_back(make_pair(a,x));
        }
        int ans=0;
        for(int y=1;y<=n;y++) dist[y]=inf;
        shortest_path(src);
        for(int l=1;l<=n;l++)
        {
            if(dist[l]<=tme)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    return 0;
}
