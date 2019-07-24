#include<bits/stdc++.h>

using namespace std;

const int mx=1e2+1;

bool vis[mx];
int disc[mx];
int low[mx];
int parent[mx];
bool ap[mx];
vector<int>adj[mx];

void apufind(int u)
{
    static int time=0;
    disc[u]=low[u]=time++;
    int child=0;
    vis[u]=true;
    int i;
    for(i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!vis[(v)]) {child++ ;
        parent[v]=u ;
        apufind(v);

        low[u]=min(low[u],low[v]);

        if(parent[u]==-1 && child>1)
        {
            ap[u]=true; // root
        }
        if( parent[u]!=-1 && low[v]>=disc[u])
        {
            ap[u]=true; // there is a back edge if it is disconnected , so connected component will be increased
        }
        }
        else if(parent[u]!=v)
        {
            low[u]=min(low[u],disc[v]);
        }

    }
}

int main()

{
    int n,m,q,a,b,index;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        vis[i]=false;
        ap[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            apufind(i);
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>index;
        int ans= (int) (adj[index].size());// when one point is articulation point , if it removes - connected to it will be disconnected
        if(ap[index])
        {
            cout<<"Satisfied "<<ans<<endl;
        }
        else
        {
            cout<<"Not Satisfied"<<endl;
        }
    }
    return 0;
}
