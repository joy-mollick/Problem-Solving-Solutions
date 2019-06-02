#include<bits/stdc++.h>

using namespace std;

const int mx=1e3+1;

typedef pair<int,int> pi;

bool visited[mx][mx];
int dis[mx][mx];
int matrix[mx][mx];
int n,m;

vector<pi> vec={{0,1},{0,-1},{1,0},{-1,0}};

bool isvalid(int a,int b)
{
	if(a>=0 && a<=n && b>=0 && b<=m && matrix[a][b] == 1)
		return true;

	return false;
}

void solution()
{
    int x,y,xx,yy;
    queue<pi>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==2)
            {
                dis[i][j]=0;
                visited[i][j]=true;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty())
    {
        pi temp=q.front();
        q.pop();
        x=temp.first;
        y=temp.second;
        for(int j=0;j<vec.size();j++)
        {
            xx = x+vec[j].first;
            yy = y+vec[j].second;

            if( isvalid(xx,yy) && visited[xx][yy]==false)
            {
                visited[xx][yy]=true;
                dis[xx][yy]=dis[x][y]+1;
                matrix[xx][yy]=2;
                q.push(make_pair(xx,yy));
            }
        }
    }

}
int main()

{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    memset(visited,false,sizeof(visited));
    solution();
    int mx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==1)
            {
                cout<<"-1"<<endl;
                return 0;
            }
            if(matrix[i][j]==2)
            {
                mx=max(mx,dis[i][j]);
            }
           // cout<<dis[i][j]<<" ";
        }
       // cout<<endl;
    }
    cout<<mx<<endl;
    return 0;
}
