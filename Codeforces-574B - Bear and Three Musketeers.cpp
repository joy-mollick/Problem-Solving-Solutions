#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int mx =4001;

vector<int>graph[mx];
bool mat[mx][mx];
int recog[mx];

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
       int n,m;
   cin>>n>>m;
   int u,v;
   memset(mat,false,sizeof(mat));
   memset(recog,0,sizeof(recog));
   while(m--)
   {
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
       mat[u][v]=true;
       mat[v][u]=true;
       recog[u]++;
       recog[v]++;
   }
   int ans=INT_MAX;
   int res=0;
   for(int i=1;i<=n;i++)
   {
       if(graph[i].size()>1){
       for(int j=1;j<=n;j++)
       {
           if(mat[i][j]&&graph[j].size()>1&&j!=i){
           for(int k=1;k<=n;k++)
           {
               if(k!=i&&k!=j&&graph[k].size()>1&&mat[k][j]&&mat[k][i])
               {
                   res=(recog[i]-2+recog[j]-2+recog[k]-2);
                   ans=min(ans,res);
               }
           }
       }
       }
       }
   }
   if(ans==INT_MAX) cout<<"-1"<<endl;
   else cout<<ans<<endl;
}
