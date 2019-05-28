#include<bits/stdc++.h>

using namespace std;

bool visited[100001];
vector<int>v[100001];
int child[100001];
int parent[100001];
set<int>happy;

void bfs(int s)
{
    visited[s]=true;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int nw=q.front();
        q.pop();
    vector<int>::iterator it;
    for(it=v[nw].begin();it!=v[nw].end();it++)
    {
        if(!visited[(*it)])
        {
            visited[(*it)]=true;
            q.push((*it));
            child[nw]++;
            parent[(*it)]=nw;
        }
    }
    }
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    if(m==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    while(m--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
    for(int i=0;i<100001;i++)
    {
        child[i]=0;
        parent[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
             bfs(i);
        }
    }
    int answer=0;
    for(int i=1;i<=n;i++)
    {
        if(child[parent[i]]<child[i])
        {
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}
