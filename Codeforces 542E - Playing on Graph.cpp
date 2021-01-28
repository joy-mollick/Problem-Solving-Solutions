
/// Codeforces 542E - Playing on Graph 
/// Only DFS + BFS 
/// Nice one !

/// When two points are not connected ,then one will be deleted 
/// We have to find the maximum chain's length 
/// So, check the odd cycle which reflects the impossible 
/// So, find the chain length of each connected component 

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxx=100003;

vector<int>adj[maxx];

bool visited[maxx];
/// it will keep the chain length of a particular connected component i
int max_chain_len[maxx];
int color[maxx];
/// it will take distance from particular node in a connected component
int dist[maxx];
/// store the number of connected component in which the node i exists
int num_of_cnnctd_cmpnnt[maxx];

int num=0;

bool isBipartite( int v)
{
    num_of_cnnctd_cmpnnt[v]=num;

    for (int u : adj[v]) {

        // if vertex u is not explored before
        if (visited[u] == false) {

            // mark present vertic as visited
            visited[u] = true;

            // mark its color opposite to its parent
            color[u] = !color[v];

            // if the subtree rooted at vertex v is not bipartite
            if (!isBipartite( u))
                return false;
        }

        // if two adjacent are colored with same color then
        // the graph is not bipartite
        else if (color[u] == color[v])
            return false;
    }
    return true;
}

int main()
{
    queue<int>Q;
    int n,m,a,b;
    cin>>n>>m;

    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visited,false,sizeof(visited));
    bool odd_cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            num++;
            if(!isBipartite(i)) odd_cycle=true;
        }
    }

    if(odd_cycle) {cout<<"-1"<<endl;return 0;}
    
    /// Every time , we start our distance counting from a particular node 

    	for(int i=1;i<=n;i++)
   {
		for(int j=1;j<=n;j++) {dist[j] = INT_MAX;}
		dist[i] = 0;
		Q.push(i);
		while(!Q.empty())
        {
			int u = Q.front();
			max_chain_len[num_of_cnnctd_cmpnnt[i]] = max(max_chain_len[num_of_cnnctd_cmpnnt[i]], dist[u]);
			Q.pop();
			for(int v : adj[u]) 
			{
			    
			if(dist[v] == INT_MAX)
            {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
			
			}
		}
	}

	int ans=0;

	for(int i=1;i<=num;i++) ans+=max_chain_len[i];

	cout<<ans<<endl;

    return 0;
}
