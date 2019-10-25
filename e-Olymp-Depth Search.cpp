#include<bits/stdc++.h>

using namespace std;


const int mx=101;
vector<int>adj[mx];
bool vis[mx];
int conn=0;

void dfs(int u)
{
   vis[u]=true;
   conn++;
   vector<int>::iterator it;
   for(it=adj[u].begin();it!=adj[u].end();it++)
   {
       if(!vis[(*it)])
       {
           dfs((*it));
       }
   }
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,a;
    cin>>n>>s;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            if(a==1){
            adj[i].push_back(j);
            adj[j].push_back(i);
            }
        }
    }
    dfs(s);
   cout<<conn<<endl;
}
