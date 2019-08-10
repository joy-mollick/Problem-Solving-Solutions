#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int mx=1e4+1;

vector<int>v[mx];
int cont=0;
bool vis1[mx];
bool vis2[mx];

bool cyclic(int u,int parent,bool vis[])
{
    vis[u]=true;
    for(int i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            if(cyclic(v[u][i],u,vis))
            {
                return true;
            }
        }
        else if(v[u][i]!=parent)
        {
            return true;
        }
    }
    return false;
}

void dfs(int u,bool vis[])
{
    vis[u]=true;
    for(int i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i],vis);
        }
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(vis1,false,sizeof(vis1));
    memset(vis2,false,sizeof(vis2));
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis1[i])
        {
            if(cyclic(i,-1,vis1))
            {
                cycle=true;
            }
        }
    }
    dfs(1,vis2);
    bool disconnected=false;
    for(int i=1;i<=n;i++)
    {
        if(vis2[i]==false)
        {
            disconnected=true;
        }
    }
    if(cycle||disconnected)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}
