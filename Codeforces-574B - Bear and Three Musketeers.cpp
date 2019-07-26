

#include<bits/stdc++.h>

using namespace std;

const int mx=4001;
vector<int>adj[mx];
int graph[mx][mx];

int main()

{
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=INT_MAX;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j && graph[i][j]==1)
            {
                for(int k=1;k<=n;k++)
                {
                    if(k!=i && k!=j && graph[i][k]==1 && graph[j][k])
                    {
                        int w=((int)adj[i].size()-2);
                        int x=((int)adj[j].size()-2);
                        int y= ((int)adj[k].size()-2);
                        ans=min(ans,w+x+y);
                    }
                }
            }
        }
    }
    if(ans==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
