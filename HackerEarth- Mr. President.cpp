#include<bits/stdc++.h>

using namespace std;

typedef pair< int ,int>pii;
const int mx = 1e6+5;
vector<pii>adj[mx];
bool marked[mx]={false};
unsigned long long mncst;
priority_queue<int>vec;

void prim_algorithm(int x)
{
    mncst=0;
    priority_queue<pii,vector<pii>,greater<pii> >q; // increasing order
    pii p;
    q.push(make_pair(0,x));
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        int  x=p.second;
        if(marked[x]==true){
        continue;}

        mncst+=(unsigned long long)(p.first);
        vec.push((p.first));
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

    int N,M,U,V,W;
    unsigned long long K;
    cin>>N>>M>>K;
    while(M--)
    {
        cin>>U>>V>>W;
        adj[U].push_back(make_pair(W,V));
        adj[V].push_back(make_pair(W,U));
    }
    prim_algorithm(1);
     bool disconnected=false;
    for(int l=1;l<=N;l++)
    {
        if(marked[l]==false)
        {
            disconnected=true;
        }
    }
    if(disconnected)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    unsigned long long  cost=mncst;
    if(cost<=K)
    {
        cout<<"0"<<endl;
    }
    else
    {
        int count=0;
        while(vec.empty()==false && cost>K)
        {
            unsigned long long tp=(unsigned long long) (vec.top());
            vec.pop();
            cost=cost-tp;
            cost++;// for super roads 1
            count++;
        }
        if(cost<=K)
        {
            cout<<count<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
