#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;
const unsigned long long int mod=1e9+7;

vector<int>adj[mx];
vector<int>rev[mx];
bool vis[mx];
bool nw_vis[mx];
vector<int>ans;
unsigned long long int cost[mx];
stack<int>s;
unsigned long long int value=0;
map<unsigned long long int,unsigned long long int>m;

void dfs(int u)
{
  vis[u]=true;
  int v;
  for(int i=0;i<adj[u].size();i++)
  {
       v=adj[u][i];
      if(!vis[v])
      {
          dfs(v);
      }
  }
  s.push(u);
}

void dfs2(int u)
{
    nw_vis[u]=true;
    //cout<<u<<endl;
    value=min(value,cost[u]);
    m[cost[u]]++;
    for(int i=0;i<rev[u].size();i++)
    {
        int v=rev[u][i];
        if(!nw_vis[v])
        {
            dfs2(v);
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,u,v,w,e;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
    }
    cin>>e;
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back((v));
        rev[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
            if(!vis[i]){
           dfs(i);}
    }
    memset(nw_vis,false,sizeof(nw_vis));
    unsigned long long int ans=0;
    unsigned long long int count=1;
    while(!s.empty())
    {
        int u=s.top();
        value=INT_MAX;
        if(!nw_vis[u])
        {
            dfs2(u);
            ans=(ans+value);
            if(m[value]>=0)
            count=((count%mod)*m[value])%mod;
            m.clear();
        }
        s.pop();
    }
    cout<<(ans)<<" "<<(count%mod)<<endl;
    return 0;
}
