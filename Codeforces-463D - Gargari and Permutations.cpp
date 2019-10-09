
#include<bits/stdc++.h>

using namespace std;

const int mx=1001;
vector<int>adj[mx];
bool used[mx];
int ans=0;
int pos[8][mx];
int level[mx];

void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(!used[adj[v][i]])
        {
            dfs(adj[v][i]);
        }
        level[v]=max(level[v],level[adj[v][i]]+1);
    }
    level[v]=max(level[v],1);
    ans=max(ans,level[v]);
    // cout<<ans<<" "<<v<<endl;
}

int main()

{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n,k,a;
   cin>>n>>k;
   for(int i=1;i<=k;i++)
   {
       for(int j=1;j<=n;j++)
       {
           cin>>a;
           pos[i][a]=j;
       }
   }

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(i==j) continue;
           bool ok=true;
           for(int k1=1;k1<=k;k1++)
           {
               if(pos[k1][i]>=pos[k1][j]) ok=false;
           }
           if(ok) adj[i].push_back(j);
       }
   }
  for(int i=1;i<=n;i++) used[i]=false;
   for(int i=1;i<=n;i++)
   {
       if(!used[i])
       dfs(i);
   }
   cout<<(ans)<<endl;
   return 0;
}
