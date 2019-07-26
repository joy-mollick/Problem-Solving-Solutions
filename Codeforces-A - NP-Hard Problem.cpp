// Bicolouring problem , slightly modified

#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

vector<int>zero;
vector<int>one;
int color[mx];
vector<int>nodes[mx];

bool isPosiible(int vertex)
{
    queue<int>Q;
    Q.push(vertex);
    color[vertex]=0;
    zero.push_back(vertex);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<nodes[u].size();i++)
        {
            int v=nodes[u][i];
            if(color[v]==-1)
            {
                if(color[u]==0){
                color[v]=1;
                one.push_back(v);
                }

                else{
                    color[v]=0;
                    zero.push_back(v);
                }

                    Q.push(v);
            }
            if(color[u]==color[v])
            {
                return false;
            }

        }
    }

}



int main()

{
    int n,m,a,b;
    cin>>n>>m;
    int ver=INT_MAX;
    while(m--)
    {
        cin>>a>>b;
        ver=min(a,min(b,ver));
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        color[i]=-1;
    }
    for(int i=1;i<=n;i++){
            if(color[i]==-1){
            if(nodes[i].size()==0){ // This node has no connection with other nodes
            continue;}

    if(!isPosiible(i))
    {
        cout<<"-1"<<endl;
        return 0;
    }
            }
    }
        cout<<(int)zero.size()<<endl;
        for(int j=0;j<zero.size();j++)
        {
            cout<<zero[j]<<" ";
        }
        cout<<endl;

        cout<<(int)one.size()<<endl;
         for(int j=0;j<one.size();j++)
        {
            cout<<one[j]<<" ";
        }
        cout<<endl;
}
