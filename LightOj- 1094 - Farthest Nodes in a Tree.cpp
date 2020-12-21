
/// Time- 0.265s
/// LightOj- 1094 - Farthest Nodes in a Tree 
/// Diameter of a tree 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int mx=30001;

vector<pair<int,int> >v[mx];
bool vis[mx];
int dist1[mx];
int dist2[mx];

 int n,a,b;

int max_index (int u,int dist[])
{
   memset(vis,false,sizeof(vis));
   memset(dist,0,sizeof(dist));
   vis[u]=true;
   queue<int>q;
   q.push(u);
   dist[u]=0;
   while(!q.empty())
   {
       int u=q.front();
       q.pop();
       for(int i=0;i<v[u].size();i++)
       {
           int V=v[u][i].first;
           int weight=v[u][i].second;
           if(!vis[V])
           {
               vis[V]=true;
               dist[V]=(dist[u]+weight);
               q.push(V);
           }
       }
    }

    int index,mx_dist=0;
    for(int i=0;i<n;i++)
    {
        if(mx_dist<dist[i])
        {
            mx_dist=dist[i];
            index=i;
        }
    }

    return index;
}

int main()

{
    int T,w;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
        for(int i=0;i<mx;i++)
        {
            v[i].clear();
            dist1[i]=0;
            dist2[i]=0;
        }
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b>>w;
        v[a].push_back(make_pair(b,w));
        v[b].push_back(make_pair(a,w));
    }
    int mx_dstance_indx=max_index(0,dist1);
    int fnal_dstnce_indx=max_index(mx_dstance_indx,dist2);
    printf("Case %d: %d\n",caso,dist2[fnal_dstnce_indx]);
    }
    return 0;
}
