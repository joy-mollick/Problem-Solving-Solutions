

#include<bits/stdc++.h>

using namespace std;

const int mx=1e3+1;

typedef pair<int,int>pii;
vector<int>adj[mx];
int cost[mx];
vector<pii>pq;
int ans=0;

int main()

{
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        cost[i]=c;
        pq.push_back(make_pair(c,i));
    }
    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sort(pq.rbegin(),pq.rend());
    int count=0;
    for(int i=0;i<pq.size();i++)
    {
        count=0;
        int u=pq[i].second;
        for(int j=0;j<adj[u].size();j++)
        {
            count=count+cost[adj[u][j]];
        }
        cost[u]=0;
        //cout<<u<<" "<<count<<endl;
        ans=ans+count;
    }
    cout<<ans<<endl;
}
