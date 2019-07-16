#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;

typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >pq;

bool visited[MAX]={false};
vector<P>adj[MAX];
long minimum_cost=0;

void prim(int src)
{
    pq.push(make_pair(0,src));
    minimum_cost=0;
    P pr;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pr=pq.top();
        pq.pop();

        if(visited[u]==false) visited[u]=true;

        else
        continue;

        minimum_cost+=pr.first;

        vector<P>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
           int v= (*it).first;
           int weight=(*it).second;
          if(visited[v]==false)
          {
              pq.push(make_pair(weight,v));
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
        adj[v].push_back(make_pair(u,w));
    }
    prim(1);
    cout<<minimum_cost<<endl;
    return 0;
}
