
/// Codeforces : 1082D - Maximum Diameter Graph.
/// Category : graph + implementation.


/// It is known that if we want to make maximize the diameter of the graph
/// Then it should be tree
/// So, a tree has n-1 edges ,if total degrees can't fill up it
/// Then it's impossible to make the graph .

#include<bits/stdc++.h>


using namespace std;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int degree[n+1];
    for(int i=1;i<=n;i++) cin>>degree[i];

    vector<int>leaf;
    vector<int>other;

    int sum=0;

    for(int i=1;i<=n;i++)
    {
        /// these will be leaf nodes
        if(degree[i]==1)
        {
            leaf.push_back(i);
        }
        /// these will be other nodes
        else
        {
            other.push_back(i);
        }

        sum+=degree[i];
    }

    if(sum/2<(n-1)) {cout<<"NO"<<endl;return 0;}

    vector<pair<int,int> >ans;
    /// making linear tree
    for(int i=1;i<(int)other.size();i++)
    {
        ans.push_back(make_pair(other[i-1],other[i]));
        degree[other[i]]--;
        degree[other[i-1]]--;
    }

     if((int)leaf.size()==1)
    {
            ans.push_back(make_pair(leaf[0],other[0]));
            degree[leaf[0]]--;
            degree[other[0]]--;

            cout<<"YES ";
            cout<<(int)other.size()<<endl;
    }

    else if((int)leaf.size()>1)
    {
        int pos=0;
        /// it is greedy to add two end of the tree to make diameter maximize
        ans.push_back({other[0],leaf[0]});
        degree[other[0]]--;
        ans.push_back({other[other.size()-1],leaf[1]});
        degree[other[other.size()-1]]--;
        ///two already gone
       for(int i=2;i<(int)leaf.size();i++)
       {
           while(!degree[other[pos]]) pos++;
           ans.push_back(make_pair(leaf[i],other[pos]));
           degree[other[pos]]--;
       }
       cout<<"YES ";
       /// diameter will be 2(two leaf nodes at the begin and the end) + other size -1 .
       cout<<(int)other.size()+1<<endl;
    }

    else if((int)leaf.size()==0)
    {
        cout<<"YES ";
        cout<<(int)other.size()-1<<endl;
    }

     printf("%d\n",ans.size());
    for(int i=0;i<(int)ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);

	return 0;
}
