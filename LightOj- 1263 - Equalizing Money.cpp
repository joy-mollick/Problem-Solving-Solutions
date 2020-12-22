/// Time-   0.370 s
/// LightOj- 1263 - Equalizing Money
/// DFS + Easy 


/// A nice question and easy question.

#include<bits/stdc++.h>

using namespace std;


int n;
const int sz=10001;

vector<int>adj[sz];

bool vis[sz];
int money[sz];
int total=0;
int people=0;

int initia()
{
    for(int i=0;i<sz;i++) {adj[i].clear();vis[i]=false;}
}

void DFS(int u)
{
    total+=money[u];
    people++;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(vis[v]==false)
        {
            DFS(v);
        }
    }
}

int main()

{
    int T,w,n,m,u,v;
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++)
    {
        initia();
        int sum=0;
       scanf("%d%d",&n,&m);
       for(int i=0;i<n;i++) {cin>>money[i],sum+=money[i];}
       while(m--)
       {
       cin>>u>>v;
       u--;v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
       }
       bool ok=true;

       /// It will no
       if(sum%n!=0) {printf("Case %d: ",caso);printf("No\n");}

       else
       {
         int average=sum/n; /// getting equal .

         for(int i=0;i<n;i++)
         {
             people=0;
             total=0;

             if(vis[i]==0)
             {
                 DFS(i);

                 if(total%people!=0)
                 {
                     ok=false;
                     break;
                 }

                 else
                 {
                     if(average!=(total/people))
                     {
                         ok=false;
                         break;
                     }
                 }
             }
         }

         printf("Case %d: ",caso);
         if(ok) printf("Yes\n");
         else printf("No\n");

       }

    }
    return 0;
}
