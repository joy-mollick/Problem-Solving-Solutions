/* Here exactly , U have to find out the route from s to d where maximum peaople can travel 
( minimum people capacity of this route ) , 
because minimum number of trips are needed ,when maximum people can travel then trips will be reduced !!
Now , use dijkstra slightly changed like as we will take the maximum capacity edges keep the track of minimum of this route 
and make this distance of the destination (d ) and keep the track of parent of the nodes .
By traversing parent from destination we will reach our source ... 
Here all time one extra man who will guide the travellers .Keep this mind .My normal code 
*/



#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>pii;
const int mx=1e6;
bool vis[mx];
int parent[mx];
vector<pii>adj[mx];
int dist[mx];

void dijkstra(int source)
{
    priority_queue<pii>q;
    dist[source]=1000000007;
    parent[source]=source;
    q.push(make_pair(dist[source],source));
    while(!q.empty())
    {
        pii pq=q.top();
        q.pop();
        int u=pq.second;
        if(vis[u])
        {
            continue;
        }
        vis[u]=true;
        vector<pii>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).second;
            int capacity=(*it).first;
            int lwmn=min(dist[u],capacity);
            if(lwmn>dist[v])
            {
                parent[v]=u;
                dist[v]=lwmn;
                q.push(make_pair(dist[v],v));
            }
        }
    }
}

int main()

{
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        dist[i]=0;
        vis[i]=false;
    }
    int s,d,c;
    while(m--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    cin>>s>>d>>c;
    dijkstra(s);
    vector<int>ans;
    ans.push_back(d);
    int t=d;
    while(t!=s)
    {
        t=parent[t];
        ans.push_back(t);
    }
    for(int j=ans.size()-1;j>=0;j--)
    {
        cout<<ans[j]<<" ";
    }
    cout<<endl;
    int total_people_can_be_travel_this_route = dist[d]-1;
    if(c%total_people_can_be_travel_this_route==0)
    {
        cout<<(c/total_people_can_be_travel_this_route)<<endl;
    }
    else
    {
        cout<<(c/total_people_can_be_travel_this_route)+1<<endl;
    }

    return 0;
}
