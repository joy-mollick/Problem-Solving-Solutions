#include<bits/stdc++.h>

using namespace std;

const int mx=700;

typedef pair<int,int> pi;
vector<pi>ans;

vector<int>adj[mx];
int low[mx];
int disc[mx];
int parent[mx];
bool visited[mx];
int s,t;

void apufind(int u)
{
    static int time=0;
    int child=0;
    visited[u]=true;
    disc[u]=low[u]=++time;
    int it;
    for(it=0;it<adj[u].size();it++)
    {
        int v=adj[u][it];
        if(!visited[v])
        {
            child++;
            parent[v]=u;
            apufind(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]) {ans.push_back(make_pair(min(u,v),max(u,v)));}
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,n,m,k,a,b,c;
    cin>>tc;
    for(int l=1;l<=tc;l++)
    {
        cout<<endl;
        cout<<"Caso #"<<l<<endl;
        cin>>n>>m;
        s++,t++;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            low[i]=0;
            disc[i]=0;
            parent[i]=-1;
            visited[i]=false;
            ans.clear();
        }
        while(m--)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
                apufind(1);

        if(ans.size()==0)
            cout<<"Sin bloqueos"<<endl;
        else{
        cout<<ans.size()<<endl;
        sort(ans.begin(),ans.end());
        for(int m=0;m<ans.size();m++)
        {
            cout<<ans[m].first<<" "<<ans[m].second<<endl;
        }

        }
    }
    return 0;
    }
