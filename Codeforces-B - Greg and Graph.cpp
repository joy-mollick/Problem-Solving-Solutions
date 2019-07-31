
#include <bits/stdc++.h>

using namespace std;

const int mx=501;

typedef unsigned long long int ll;

ll adj[mx][mx];
ll dist[mx][mx];
ll v;
int node=INT_MAX;
ll sum=0;
ll md=1e14;

vector<ll>ans;
bool is_delt[mx];

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    cin>>v;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cin>>adj[i][j];
        }
    }
    int delt_vertex[v+1];
    for(int i=v;i>=1;i--)
    {
        cin>>r;
        delt_vertex[i]=r;
    }
    memset(is_delt,false,sizeof(is_delt));
    ll sum[v+1]={0};
    for(int k=1;k<=v;k++)
    {
        int vertex=delt_vertex[k];
        is_delt[vertex]=true;
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                adj[i][j]=min(adj[i][j],adj[i][vertex]+adj[vertex][j]);
                if(is_delt[i]&&is_delt[j])
                {
                    sum[k]+=adj[i][j];
                }
            }
        }
    }
    for(int i=v;i>=1;i--)
    {
        cout<<sum[i]<<" ";
    }
    cout<<endl;
}
