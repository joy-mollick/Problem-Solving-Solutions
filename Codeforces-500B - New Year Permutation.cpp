#include<bits/stdc++.h>

using namespace std;

int finally_visited[302];
int ans;
int arr[302];
vector<int>adj[302];
bool vis[302];
void dfs(int index,bool*vis)
{
    vis[index]=true;
    if(!finally_visited[index]) ans =min(arr[index],ans); // if that index has been replaced already by minimum number of that , so leave it

    for(int i=0;i<adj[index].size();i++)
    {
        if(!vis[adj[index][i]])
        {
            dfs(adj[index][i],vis);
        }
    }
}

int main()

{

    int n;
    cin>>n;
    int position[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        position[arr[i]]=i; // taking position of a number !!
    }
    char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c;
            if(c=='1')
            {
                adj[i].push_back(j); // taking the indices which (i) may be replaced by j indices
            }
        }
    }
    memset(finally_visited,false,sizeof(finally_visited));
    for(int i=0;i<n;i++)
    {
        memset(vis,false,sizeof(vis));

        ans=INT_MAX;
        dfs(i,vis); // passing index and visited array .
        finally_visited[position[ans]]=true; // that index has been replaced already by minimum number of that .so finally_visited !!
        cout<<ans<<" "; // printing ans , minimum number of that index .
    }
    cout<<endl;
    return 0;
}
