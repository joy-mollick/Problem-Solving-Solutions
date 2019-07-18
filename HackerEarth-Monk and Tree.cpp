#include<bits/stdc++.h>

using namespace std;

typedef pair< int ,int>pii;
const int mx = 1e6;
bool marked[mx]={false};
unsigned long long mncst=0;
int removedgecst=0;

void prim_algorithm(int x,vector<pii>adj[])
{
    priority_queue<pii>q; // increasing order
    pii p;
    q.push(make_pair(0,x));
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        int  x=p.second;
        if(marked[x]==true){
            mncst+=((unsigned long long)(p.first));
        continue;}

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
        cin>>U>>V;
        adj[U].push_back(make_pair(abs(U-V),V));
        adj[V].push_back(make_pair(abs(V-U),U));
    }
    unsigned long long count=0;
    for(int i=1;i<=N;i++)
    {
        if(marked[i]==false)
        {
            prim_algorithm(i,adj);
            count++;
        }
    }
    unsigned long long  cost=mncst;
    mncst=0;
    cost=(cost+(count-1));
    cout<<(cost)<<endl;
    memset(marked,false,sizeof(marked));
    }
    return 0;
}
