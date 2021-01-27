

/// Codeforces  404C - Restore Graph 
/// Greedy + graph 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx=1e5+1;

queue<int> a[mx];
vector<pair<int,int>> ans;
int n,k,t;


int bfs()
{
    queue<pair<int,int>> q;
    q.push( make_pair(a[0].front(),0) );
    while(!q.empty())
    {
        int cur = q.front().first;
        int step = q.front().second;
        q.pop();
        int degree;
        if(step==0) degree=k;
        else degree=k-1;

        while(!a[step+1].empty()&&degree)
        {
            int tt = a[step+1].front();
            a[step+1].pop();
            ans.push_back( make_pair( cur, tt) );
            q.push( make_pair(tt,step+1) );
            degree--;
        }
    }
    return 0;
}


int main()
{

    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[t].push(i);
    }

    if(a[0].size()!=1)
    {
        printf("-1\n");
        return 0;
    }

    if(a[1].size()>k)
    {
        printf("-1\n");
        return 0;
    }

        for(int i=1;i<n-1;i++)
    {
        /// if (k-1) * all nodes with distance i is less than all nodes with distance i+1
        if((ll)a[i+1].size() > (ll)a[i].size()*(k-1) )//need to use long long
        {
            printf("-1\n");
            return 0;
        }
    }

    bfs();
    int ansl =ans.size();
    printf("%d\n",ansl);
    for(int i=0;i<ansl;i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
