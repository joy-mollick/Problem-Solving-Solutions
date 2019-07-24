#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

 vector<pair<int,int>>adj[mx];
 typedef pair<int,int> pii;
 bool vis[mx];
 int dist[mx];

 void djkstra(int source)
 {
     priority_queue<pii,vector<pii>,greater<pii> >pq;
     dist[source]=0;
     pii p;
     p.first=0;
     p.second =1;
     pq.push(p);
     while(!pq.empty())
     {
         p= pq.top();
         int t =p.first;
         pq.pop();
         int u= p.second;
         if(vis[u]) continue;

         vis[u]=true;

         for(int i=0;i<adj[u].size();i++)
         {
             int v = adj[u][i].first;
             int flag = adj[u][i].second; // to reach this node , is the time should be even or odd ( 0 or 1)
             int tt=0;
             if (t%2==(flag)) // if prev-node (u) time is odd and to reach node v flag is odd(1) u can reach there within only 1 second , smae case for even
             {
                 tt=t+1;
             }
             else
             tt=t+2; // otherwise , u have to wait 1 second that node and the direction of road will be changed then u have to go v from within one more second totally 2 second

             if(dist[v]>tt)
             {
                 dist[v]=tt;
                 pq.push(make_pair(tt,v)); // tt holds for minimum time to reach node v
             }
         }
     }

 }

int main()

{
    int n,e,q,u,v,tm;
    cin>>n>>e>>q;
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(make_pair(v,0)); // u-> v edge cost holds for even seconds which represents 0
        adj[v].push_back(make_pair(u,1)); // v-> u edge cost holds for odd seconds which represents 1
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=n;i++)
    {
        dist[i]=INT_MAX;
    }
    djkstra(1);
    while(q--)
    {
        cin>>tm;
        if(tm<dist[n])
        {
            cout<<"FML"<<endl;
        }
        else
        {
            cout<<"GGMU"<<endl;
        }
    }
    return 0;
}
