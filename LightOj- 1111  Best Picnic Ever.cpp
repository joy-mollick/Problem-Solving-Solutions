
/// Time-   0.016s
/// LightOj- 1111 - Best Picnic Ever 
/// BFS 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int mx=1001;
const int inf=INT_MAX;

int N;
int cont[mx];
vector<int>adj[mx];

void initi ()
{
   for(int i=0;i<mx;i++)
   {
       adj[i].clear();
       cont[i]=0;
   }
}

void BFS (int src)
{
   bool vis[mx];
   for(int i=1;i<=N;i++) vis[i]=false;
   queue<int>q;
   q.push(src);
   vis[src]=true;
   cont[src]++;
   while(!q.empty())
   {
       int u=q.front();
       q.pop();
       for(int i=0;i<adj[u].size();i++)
       {
           int v=adj[u][i];
           if(!vis[v])
           {
               q.push(v);
               vis[v]=true;
               cont[v]++;
           }
       }
   }

}

int main()

{
    int T,w,query;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
       initi();
       int K,M,u,v;
       scanf("%d%d%d",&K,&N,&M);
       int places[K];
       for(int i=0;i<K;i++) scanf("%d",&places[i]);
       while(M--)
       {
           scanf("%d%d",&u,&v);
           adj[u].push_back(v);
       }
       for(int i=0;i<K;i++) BFS(places[i]);
       int ans=0;
       for(int i=1;i<=N;i++)
       {
           if(cont[i]==K) {ans++;}
       }
       printf("Case %d: %d\n",caso,ans);
    }
    return 0;
}
