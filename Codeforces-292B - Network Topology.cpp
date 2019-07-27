#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;
bool vis[mx];
vector<int>adj[mx];
int n;

bool star()
{
    bool ans;
    int count1=0;
    int other=0;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            count1++;
        }
        else if(adj[i].size()==n-1)
        {
            other++;
        }
    }
    if(other==1&&count1==n-1)
    {
        ans=true;
    }
    else{
        ans=false;
    }
    return ans;
}

bool ring()
{
    bool ans=true;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()!=2)
        {
            ans=false;
            break;
        }
    }
    return ans;
}

bool bus()
{
    bool ans;
    int one=0;
    int two=0;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            one++;
        }
        else if(adj[i].size()==2)
        {
            two++;
        }
    }
    if(one==2 && two==n-2)
    {
        ans=true;
    }
    else{
        ans=false;
    }
    return ans;
}
int main()

{
    int m,k,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(star())
    {
        cout<<"star topology"<<endl;
    }
    else if(bus())
    {
        cout<<"bus topology"<<endl;
    }
    else if(ring())
    {
        cout<<"ring topology"<<endl;
    }
    else{
        cout<<"unknown topology"<<endl;
    }
}
