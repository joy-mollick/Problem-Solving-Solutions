
/// Time-   0.003s
/// LightOj 1049 - One Way Roads 
/// Greedy Graph Theory.

#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

int main()
{
    int T;
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++)
    {
        int n,u,v,w;
        scanf("%d",&n);
        int left_side[n+1];
        int right_side[n+1];
        memset(left_side,0,sizeof(left_side));
        memset(right_side,0,sizeof(right_side));
        int straight=0;
        int reverses=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            /// it is only for one side left to right
            if(left_side[u]==0 && right_side[v]==0)
            {
                straight+=w;
                left_side[u]=right_side[v]=1;
            }
            /// it is only for reverse right to left
            else
            {
                right_side[u]=left_side[v]=1;
                reverses+=w;
            }
        }
        printf("Case %d: %d\n",caso,min(straight,reverses));
    }
    return 0;
}
