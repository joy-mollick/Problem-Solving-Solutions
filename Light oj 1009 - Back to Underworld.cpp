
/// Time -   0.345s
/// Light oj 1009 - Back to Underworld
/// Graph theory + Bipartite.

#include<bits/stdc++.h>

using namespace std;

const int maxn=20001;

const int BLACK=1;
const int RED=2;
const int WHITE=0;

vector<int>adj[maxn];
int color[maxn];
int vampire=0;
int lykan=0;
int ans=0;

void clear_adj()
{
  for(int i=0;i<maxn;i++) adj[i].clear();
}

void BFS(int s)
{
   queue<int>q;
   color[s]=BLACK; /// consider it as vampire and color it as BLACK
   vampire++; /// as first one is evaluated
   q.push(s);

   while(!q.empty())
   {
       int u=q.front();
       q.pop();

       for(int i=0;i<adj[u].size();i++)
       {
           int v=adj[u][i];
           /// if not marked ,then marked as RED or BLACK
           if(color[v]==WHITE)
           {
              q.push(v);
              if(color[u]==BLACK)
              {
                  color[v]=RED;
                  lykan++;
              }
              else
              {
                  color[v]=BLACK;
                  vampire++;
              }
           }
       }
   }

}

int main()

{
    int T,n,u,v;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
       clear_adj();
       memset(color,0,sizeof(color));

       vampire=0;
       lykan=0;
       ans=0;

       cin>>n;

       while(n--)
       {
           cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }

       for(int i=0;i<maxn;i++)
       {
           ///if i is in different connected component
           if(!adj[i].empty() && color[i]==WHITE)
           {
               vampire=0;
               lykan=0;
               BFS(i);
               ans=ans+max(lykan,vampire);
           }
       }

       printf("Case %d: %d\n",caso,ans);

    }
    return 0;
}
