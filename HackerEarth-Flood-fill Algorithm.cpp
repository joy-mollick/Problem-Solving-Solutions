#include<bits/stdc++.h>

using namespace std;

const int mx=11;
int mat[mx][mx];
int n,m;

void dfs(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j]==0) return ;

    mat[i][j]=0;// when reaching here , this index becomes zero

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main()

{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    dfs(0,0);

    if(mat[n-1][m-1]==0)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
