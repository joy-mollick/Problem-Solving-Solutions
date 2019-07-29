#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,p,tota;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        int graph[n+1][n+1];
        memset(graph,0,sizeof(graph));
        tota=2*n+p;
        for(int i=1;i<=n&&tota>=0;i++)
        {
            for(int j=1;j<=n&&tota>=0;j++)
            {
                if(i!=j&&graph[i][j]==0){
                cout<<i<<" "<<j<<endl;
                --tota;
                graph[i][j]=1;
                graph[j][i]=1;
                }
                if(tota==0)
                {
                    break;
                }
            }
            if(tota==0)
                {
                    break;
                }
        }

    }
}
