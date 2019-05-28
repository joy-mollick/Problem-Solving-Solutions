#include<bits/stdc++.h>

using namespace std;

bool visited[1001];
int dist[1001];

void bfs(vector<int>v[])
{
    visited[1]=true;
    queue<int>q;
    dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        vector<int>::iterator it;
        for(it=v[temp].begin();it!=v[temp].end();it++)
        {
            if(!visited[(*it)])
            {
                dist[(*it)]=dist[temp]+1;
                q.push((*it));
                visited[(*it)]=true;
            }
        }
    }
}

int main()

{
    int n,m,u,t,q,gf;
    cin>>n;
    m=n-1;
    vector<int>v[n+1];
    while(m--)
    {
        cin>>u>>t;
        v[u].push_back(t);
        v[t].push_back(u);
    }
    cin>>q;
    vector<int>girls;
    while(q--)
    {
        cin>>gf;
        girls.push_back(gf);
    }

    for(int i=0;i<=1000;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    bfs(v);
    int girldis=dist[girls[0]];
    int girlid=girls[0];
    for(int i=1;i<girls.size();i++)
    {
        //cout<<girls[i]<<" "<<dist[girls[i]]<<endl;
        if(girldis>dist[girls[i]])
        {
            girldis=dist[girls[i]];
            girlid=girls[i];
        }
    }
    cout<<girlid<<endl;
    return 0;
}
