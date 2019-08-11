#include <bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

vector<int>adj[mx];
int color[mx];

bool possible(int source)
{
    queue<int>q;
    q.push(source);
    color[source]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(color[v]==-1)
            {
                if(color[u]==0)
                    color[v]=1;
                else
                    color[v]=0;

                q.push(v);
            }
            if(color[u]==color[v])
                return false;
        }
    }
    return true;
}

int main()

{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int tc,n,m,a,b;
   cin>>tc;
   int r=1;
   while(tc--)
   {
       cin>>n>>m;
         for(int i=1;i<=n;i++)
       {
           color[i]=-1;
           adj[i].clear();
       }
       while(m--)
       {
           cin>>a>>b;
           adj[a].push_back(b);
           adj[b].push_back(a);
       }
       cout<<"Scenario #"<<r<<":"<<endl;
       bool ok=true;
       for(int j=1;j<=n;j++)
       {
           if(color[j]==-1){
       if(!possible(j))
       {
           ok=false;
           break;
       }
           }

       }
       if(ok)
       {
           cout<<"No suspicious bugs found!"<<endl;
       }
       else
        cout<<"Suspicious bugs found!"<<endl;

       r++;
   }
}
