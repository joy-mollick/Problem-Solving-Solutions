#include<bits/stdc++.h>

using namespace std;

int total=0;
const int mx=1e3+1;
int arr[mx][mx];

void dfs(int i,int j,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m || arr[i][j]==0) {return ;}

    arr[i][j]=0;
    total++;
    //cout<<total<<endl;
    dfs(i+1,j,n,m);
    dfs(i-1,j,n,m);
    dfs(i,j+1,n,m);
    dfs(i,j-1,n,m);
    dfs(i+1,j+1,n,m);
    dfs(i-1,j-1,n,m);
    dfs(i-1,j+1,n,m);
    dfs(i+1,j-1,n,m);
}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //total=0;
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1){
                    total=0;
                       // cout<<"1"<<endl;
                dfs(i,j,n,m);
                count++;

                    ans=max(ans,total);
                }
            }
            total=0;
        }
        cout<<count<<" "<<ans<<endl;
    }
    return 0;
}
