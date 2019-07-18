#include<bits/stdc++.h>

using namespace std;

typedef pair< int ,int>pii;
const int mx = 1501;
const unsigned long long mod= 1e9+7;
bool marked[mx]={false};
unsigned long long mncst=1;

void prim_algorithm(int x,vector<pii>adj[])
{
    mncst=1;
    priority_queue<pii,vector<pii>,greater<pii> >q; // increasing order
    pii p;
    q.push(make_pair(1,x));
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        int  x=p.second;
        if(marked[x]==true){
        continue;}

        mncst= (mncst*((unsigned long long)(p.first)))%mod;
        marked[x]=true;

        for(int i=0;i<adj[x].size();i++)
        {
            int y=(int)(adj[x][i].second);
            if(marked[y]==false)
            {
                q.push((adj[x][i]));
            }
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--){
    int N,M,U,V,W;
    unsigned long long K;
    cin>>N>>M;
    vector<pii>adj[N+1];
    while(M--)
    {
        cin>>U>>V>>W;
        adj[U].push_back(make_pair(W,V));
        adj[V].push_back(make_pair(W,U));
    }
    prim_algorithm(1,adj);
    unsigned long long  cost=mncst;
    mncst=1;
    cout<<cost<<endl;
    memset(marked,false,sizeof(marked));
    }
    return 0;
}
