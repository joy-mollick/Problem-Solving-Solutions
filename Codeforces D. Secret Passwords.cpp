
/// Codeforces D. Secret Passwords
/// Only DFS


/// First make edges of all characters and serial no. of passwords
/// Then do dfs and keep array of visitation


#include <bits/stdc++.h>

typedef long long ll;

/// prime number greater than 10^5
const int maxx=1000003;

using namespace std;

vector<int>adj[maxx];
int vis[maxx];

void dfs(int u)
{
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(vis[v]!=-1) continue;
        vis[v]=0;
        dfs(v);
    }
}

int main()
{

    int n;
    cin>>n;
    string s;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            adj[i].push_back(n+1+(s[j]-'a'));
            adj[n+1+(s[j]-'a')].push_back(i);
        }
    }

    int ans=0;
    memset(vis,-1,sizeof(vis));

    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=-1) continue;
         dfs(i);ans++;
    }

    cout<<ans<<endl;

    return 0;
}
