
/// Codeforces D - Mouse Hunt 
/// dsu problem 
/// Nice problem!!


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxx=200002;

int father[maxx];
int next_sec[maxx];
int cost[maxx];
int bl[maxx];

int find_final_fath(int x)
{
    return x == father[x] ? x : father[x] = find_final_fath(father[x]);
}

/// finding minimum cost one amongst a block
int dfs(int fa,int x)
{
        if(fa == x) return cost[fa];
        return min(dfs(next_sec[fa], x), cost[fa]);
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {cin>>cost[i];father[i] = i;}

    for(int i = 1; i <= n; i++) cin>>next_sec[i];

    for(int i = 1; i <= n; i++)
    {
        /// that means father of this block
        if(find_final_fath(next_sec[i])==find_final_fath(i))
        {
            bl[i]=1;
            continue;
        }
        father[find_final_fath(next_sec[i])] = find_final_fath(i);
    }

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        if(bl[i])
        {
            ans+=dfs(next_sec[i],i);
        }
    }

    cout<<ans<<endl;

    return 0;
}
