
/// Codeforces 782E - E. Underground Lab
/// DFS Problem
/// Nice problem!!


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxx=200002;

vector<int>adj[maxx];
vector<int>ans;
int vis[maxx];
int n,m,k;

void dfs(int u)
{
    vis[u] = 1;
    ans.push_back(u);
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]) continue;
        dfs(v);
        ans.push_back(u);
    }
}

int main()
{

     int u,v;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /// a dfs eulerian path where total there are 2*n entries
    /// starting and end node is the same for eulerian path
    dfs(1);
    /// it is for the size of part if we take eulerian path
    /// every starting node is another count for path , so total entries will be 2*n-1+k
    int stp = (2*n+k-1)/k;
    for(int i = 0; i < k; i++)
    {
        int beg = i*stp, ends = min((i+1)*stp, (int)ans.size());
        if(ends <= beg)
        {
            printf("1 1\n");
            continue;
        }

        printf("%d", ends-beg);
        for(int j = beg; j < ends; j++)
        {
            printf(" %d", ans[j]);
        }
        puts("");
    }

    return 0;
}
