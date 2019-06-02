#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

bool visited[mx];
int firstarr[mx];
int secondarr[mx];
vector<int> swappable_elemnts_of_first;
vector<int> swappable_elemnts_of_second;
vector<int>v[mx];

void dfs(int i)
{
    visited[i]=true;
    swappable_elemnts_of_first.push_back(firstarr[i]);
    swappable_elemnts_of_second.push_back(secondarr[i]);
    vector<int>::iterator it;
    for(it=v[i].begin();it!=v[i].end();it++)
    {
        if(!visited[(*it)])
        {
            dfs((*it));
        }
    }
}

int main()

{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>firstarr[i];
        }
        for(int j=1;j<=n;j++)
        {
            cin>>secondarr[j];
        }
        while(m--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(visited,false,sizeof(visited));
        bool ok=true;
        for(int k=1;k<=n;k++)
        {
            if(!visited[k])
            {
                swappable_elemnts_of_first.clear();
                swappable_elemnts_of_second.clear();
                dfs(k);
                sort(swappable_elemnts_of_first.begin(),swappable_elemnts_of_first.end());
                sort(swappable_elemnts_of_second.begin(),swappable_elemnts_of_second.end());
                if(swappable_elemnts_of_first!=swappable_elemnts_of_second)
                {
                    ok=false;
                    //cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(ok)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        for(int p=1;p<=n;p++)
        {
            v[p].clear();
        }
    }
    return 0;
}
