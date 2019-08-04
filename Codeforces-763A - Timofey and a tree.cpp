#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

const int mx=1e5;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,u,v;
    map<int,pi>edge;
    cin>>n;
    int cost[n+1];
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        edge[i]=(make_pair(u,v));
    }
    for(int j=1;j<=n;j++)
    {
        cin>>cost[j];
    }
     map<int,pi>notequal;
     int y=0;
     bool onetime=true;
    for(int k=0;k<n-1;k++)
    {
        int u=edge[k].first;
        int v=edge[k].second;
        if(cost[v]!=cost[u])
        {
            notequal[y++]=(make_pair(u,v));
            onetime=false;
        }
    }
    if(onetime)
    {
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
        return 0;
    }
    bool ok;
    int a=notequal[0].first;
    int b=notequal[0].second;

    int arr[]={a,b};

    int ans,j,i;
        for( j=0;j<2;++j)
    {
        ok=true;
        for( i=1;i<notequal.size();i++)
        {
            if((notequal[i].first)!=arr[j] && (notequal[i].second)!=arr[j])
            {
                ok=false;
            }
        }
        if(ok)
        {
            ans=arr[j];
            break;
        }
    }
    if(ok)
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

