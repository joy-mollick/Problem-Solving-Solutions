#include<bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

#define inf INT_MAX;

typedef pair<long,long>pii;
vector<int>adj[mx];
int n,m;


void bfs(int source,int *dis)
{
   queue<int>q;
   for(int i=1;i<=n;i++)
   {
       dis[i]=inf;
   }
   dis[source]=0;
   q.push(source);
   while(!q.empty())
   {
       int u=q.front();
       q.pop();
       vector<int>::iterator it;
       for(it=adj[u].begin();it!=adj[u].end();it++)
       {
           if(dis[(*it)]>dis[(u)]+1)
           {
               dis[(*it)]=dis[(u)]+1;
               q.push((*it));
           }
       }
   }
}

int main()

{
    int u,v,s,d;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>s>>d;
    int source_to_dest[n+1];
    int dest_to_source[n+1];

    bfs(s,source_to_dest);
    bfs(d,dest_to_source);

    vector<int>level[n];
    for(int i=1;i<=n;i++)
    {
        if(i!=s && i!=d)
        {
            if(source_to_dest[i]+dest_to_source[i]==source_to_dest[d])
            {
                level[source_to_dest[i]].push_back(i);
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<=n;i++)
    {
        if(level[i].size() == 1)
        {
            ans=min(ans,level[i][0]);
        }
    }

    if(ans==INT_MAX)
    cout<<"-1"<<endl;

    else
    cout<<ans<<endl;

    return 0;
}
