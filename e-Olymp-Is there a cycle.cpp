#include<bits/stdc++.h>

using namespace std;


const int mx=51;
vector<int>adj[mx];
bool vis[mx];
bool recStack[mx];
bool cycle=false;

bool cy_dfs(int u,int parent)
{
    vis[u]=true;
    recStack[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(!vis[(*it)])
        {
            if(cy_dfs((*it),u)){
            return true;}
        }
        else if(recStack[(*it)])
        {
           return true;
        }
    }
    recStack[u]=false;
    return false;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,a;
    cin>>n;
    memset(vis,false,sizeof(vis));
    memset(recStack,false,sizeof(recStack));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            if(a==1){
            adj[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) // This node has been not visited , checking for different connected components
        {
            if(cy_dfs(i,-1))
            {
                cycle=true;
            }
        }
    }
   string res=(cycle==true)?"1":"0";
   cout<<res<<endl;
}
