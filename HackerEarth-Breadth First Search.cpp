#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,desti,u,u1;
    cin>>n;
    int m=n-1;
    vector<int>v[n+1];
    while(m--)
    {
        cin>>u>>u1;
        v[u].push_back(u1);
        v[u1].push_back(u);
    }
    cin>>desti;
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    int dist[n+1]={0};
    queue<int>q;
    dist[1]=1;
    q.push(1);
    visited[1]=true;
    while(q.empty()==false)
    {
        int temp=q.front();
        q.pop();
        for(int i=0;i<v[temp].size();i++)
        {
            if(!visited[v[temp][i]])
            {
                visited[v[temp][i]]=true;
                dist[v[temp][i]]=dist[temp]+1;
                q.push(v[temp][i]);
            }
        }
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==desti)
        {
            count++;
        }
    }
    cout<<count<<endl;

}
