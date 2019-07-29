#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

const int mx=1e5+1;

map<int, int> colors;
map<int, set<int> > card;
vector<int>adj[mx];

int main()

{
    int n,m,id,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>id;
        colors[i]=id;
    }
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mxsz=0;
    int mn_color=INT_MAX;
    for(int j=1;j<=n;j++)
    {
        int u=j;
        int v;
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(colors[u]!=colors[v])
            {
                card[colors[u]].insert(colors[v]);
            }
        }
        int sz=card[colors[u]].size();
        if(mxsz<sz)
        {
            mxsz=sz;
            mn_color=colors[u];
            //cout<<u<<" "<<sz<<endl;
        }
        else if(mxsz==sz)
        {
            if(colors[u]<=mn_color)
                mn_color=colors[u];
        }
    }
    cout<<mn_color<<endl;
    return 0;
}
