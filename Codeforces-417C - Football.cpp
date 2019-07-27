#include<bits/stdc++.h>
using namespace std;



int main()

{
    int n,k;
    scanf("%d%d",&n,&k);
    bool graph[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j){
            graph[i][j]=false;
            graph[j][i]=false;
            }
        }
    }
    int total_matches=(n*(n-1))>>1;
    int equal_win=total_matches/n;

    if(equal_win<k)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",(n*k));
    int total=n*k;
    for(int i=1;i<=n,total>0;i++)
    {
        int count=k;
        for(int j=1;j<=n,total>0;j++)
        {
            if(i!=j)
            {

                if(graph[i][j]==false)
                {
                    graph[i][j]=true;
                    graph[j][i]=true;
                    printf("%d %d\n",i,j);
                    count--;
                    total--;
                }
            }
            if(count==0)
            {
                break;
            }
        }
    }
}
