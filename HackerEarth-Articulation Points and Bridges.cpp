#include<bits/stdc++.h>

using namespace std;


vector<int>adj[13];
bool visited[12]={false};// visited or not ??
int disc[12]={0};// dfs time finding
int low[12]={0};// low time for finding cycle
int parent[12]={-1};// -1 holds for Null
bool apu[12]={false};// which vertices are articular point ?
vector< pair<int,int> >bridges; // push back the bridges into a vector
int articupoints=0;

void finding(int u)
{
    static int time=0;
    int child=0;
    visited[u]=true;
    disc[u]=low[u]=time++;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            child++;
            parent[v]=u;
            finding(v);

        low[u]=min(low[u],low[v]);
        if(parent[u]==-1 && child>1)
        {
            articupoints++;
            apu[u]=true;// finding root with different independent subtree
        }
        if(parent[u]!=-1 && low[v]>=disc[u]) // there is no way to reach v without covereing u
        {
            articupoints++;
            apu[u]=true;
        }
        if(low[v]>disc[u])
        {
            bridges.push_back(make_pair(min(v,u),max(v,u)));// storing bridges pair
        }

        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }

}

bool comp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return (a.second<b.second);
    }
    else
    {
        return (a.first<b.first);
    }
}

int main()

{
    int N,M,u,v;
    cin>>N>>M;
    while(M--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<12;i++)
    {
        if(!visited[i])
        {
            finding(i);
        }
    }
    cout<<articupoints<<endl;
    int count=0;
    for(int l=0;l<12;l++)
    {
        if(apu[l]==true)
        {
            count++;
            if(count==1)
            {
                cout<<l;
            }
            else
            {
                cout<<" "<<l;
            }
        }
    }
    cout<<endl;
    cout<<(bridges.size())<<endl;
    sort(bridges.begin(),bridges.end(),comp);
    for(int y=0;y<bridges.size();y++)
    {
        cout<<bridges[y].first<<" "<<bridges[y].second<<endl;
    }

    return 0;
}
