
#include <bits/stdc++.h>

using namespace std;


int main()

{
    int n,m,u,v;
    cin>>n>>m;
    map< int , pair<int,int> >edge;
    map< pair<int,int> , bool> edge_vis;
    int degrees[n+1];
    memset(degrees,0,sizeof(degrees));
    int i=0;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        edge[i]=make_pair(u,v);
        degrees[u]++;
        degrees[v]++;
    }
    int total_group=0;
    while(1)
    {
        vector< pair<int,int> >v;
        bool group=false;
        for(int i=0;i<m;i++)
        {
            pair<int,int>p;
            p=edge[i];
            if((degrees[p.first]==1||degrees[p.second]==1) &&edge_vis[p]==false)
            {
                v.push_back(p); // these edge(student) will be kick out from the class
                group=true;
            }
        }
        for(int j=0;j<v.size();j++)
        {
            degrees[v[j].first]--;
            degrees[v[j].second]--;
            edge_vis[v[j]]=true;// these edge has been removed by making it true
        }
        if(group==false) // that means there are no group else like we want ,so our task have been done
            break;
        else{
            total_group++;}
    }
    cout<<total_group<<endl;
}
