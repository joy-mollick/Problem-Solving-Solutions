#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,ll> ipair;

const int mx=50001;

vector<ipair>adj[mx];

int n;

ll dist[mx]={0};

int shortest_path(int src)
{
    priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
    bool vis[n+1]={false};
    pq.push(make_pair(0,src));
    for(int y=1;y<=n;y++) dist[y]=1e9;
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
            ll weight=adj[u][i].second;
            if(weight+dist[u]<dist[v])
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
     ll mx=0;
      int id;
      for(int k=1;k<=n;k++) {if(mx<dist[k]){mx=dist[k],id=k;}};

      return id;
}

int main()

{
   int t,a,b;
   ll c;
   cin>>t;
       while(t--){
            cin>>n;
      for(int i=1;i<=n;i++) adj[i].clear();
      for(int j=0;j<n-1;j++)
      {
          cin>>a>>b>>c;
          adj[a].push_back(make_pair(b,c));
          adj[b].push_back(make_pair(a,c));
      }
      int y=shortest_path(1);
      ll ans=dist[shortest_path(y)];
      cout<<ans<<endl;
   }
}
