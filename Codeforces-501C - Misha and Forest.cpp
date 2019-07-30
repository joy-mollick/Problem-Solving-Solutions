
#include <bits/stdc++.h>

using namespace std;

vector< pair<int,int> >s;

int main()

{
    int n;
    cin>>n;
    int total_edges[n];
    int xor_sum[n];
    vector<int>leaf_node;
    for(int i=0;i<n;i++)
    {
        cin>>total_edges[i]>>xor_sum[i];
        if(total_edges[i]==1)
        {
            leaf_node.push_back(i);
        }
    }
    int h=0;
    int u,v;
    while(h<leaf_node.size())

    {
        if(total_edges[leaf_node[h]]==1) // ok , this is a leaf node , it has only one adjacent node
        {
            s.push_back(make_pair(leaf_node[h],xor_sum[leaf_node[h]]));
        total_edges[leaf_node[h]]--;
        total_edges[xor_sum[leaf_node[h]]]--;
        if(total_edges[xor_sum[leaf_node[h]]]==1){
            leaf_node.push_back(xor_sum[leaf_node[h]]);
        }
        xor_sum[xor_sum[leaf_node[h]]]^=leaf_node[h];
        }
        h++;
    }



    cout<<(s.size())<<endl;
    vector< pair<int,int> >::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<(it->first)<<" "<<(it->second)<<endl;
    }
    return 0;
}
