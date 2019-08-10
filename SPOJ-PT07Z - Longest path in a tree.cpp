#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int mx=1e4+1;

vector<int>v[mx];
int cont=0;
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
           if(!vis[v[u][i]])
           {
               vis[v[u][i]]=true;
               dist[v[u][i]]=dist[u]+1;
               q.push(v[u][i]);
           }
       }
    }

    int index,mx_dist=0;
    for(int i=1;i<=n;i++)
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int mx_dstance_indx=max_index(1,dist1);
    //cout<<mx_dstance_indx<<endl;
    int fnal_dstnce_indx=max_index(mx_dstance_indx,dist2);
    //cout<<fnal_dstnce_indx<<endl;
    cout<<dist2[fnal_dstnce_indx]<<endl;
}
