#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >pq;
#define inf 1e7
vector<int>dist(10001,inf);

bool visited[100000]={false};
vector<P>adj[10001];

void short_path(int src,int V)
{
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        if(visited[u]==false) visited[u]=true;

        else
        continue;

        vector<P>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
           int v=(*it).first;
           int weight= (*it).second;

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
    int N,M,u,v,w;
    cin>>N>>M;
    while(M--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    short_path(1,N);
    int count=0;
    for(int i=2;i<=N;i++)
    {
        count++;
        if(count==1)
        {
            if(dist[i]==inf)
            cout<<"1000000000";
            else
            cout<<dist[i];
        }
        else
        {
            if(dist[i]==inf)
            cout<<" 1000000000";
            else
            cout<<" "<<dist[i];
        }
    }
    return 0;
}
