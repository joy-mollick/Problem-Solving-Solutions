
/// Codeforces D. Fix a Tree
/// Only DSU and greedy 


#include <bits/stdc++.h>

typedef long long ll;

const int maxx=1000003;

using namespace std;

int parent[maxx];

int find_parent(int u)
{
   if(parent[u]==u) return u;
   int f=find_parent(parent[u]);
   parent[u]=f;
   return f;
}

int main()
{

    int res=0;
    int root=-1,n;
    cin>>n;
    int pa[n+1];
    for(int i=0;i<=n;++i) parent[i]=i;

	for(int i=1;i<=n;++i){
		cin>>pa[i];
		if(pa[i]==i) root=i;
	}

	for(int i=1;i<=n;i++)
    {
        /// root of a tree
        if(i==root) continue;

        int fc=find_parent(i);
        int fp=find_parent(pa[i]);

        /// legal ,as fc and fp are not connected
        if(fc!=fp) parent[fc]=fp;

        /// illegal ,so change
        /// make father of root as parent of i node 
        else
        {
            res++;
            if(root==-1) root=i;
            parent[fc]=find_parent(root);
            pa[i]=parent[fc];

        }

    }

    cout<<res<<endl;
    for(int i=1;i<=n;i++) cout<<pa[i]<<" ";

    return 0;
}
