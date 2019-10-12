#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[5010];

int segment_tree(int l,int r)
{
    if(l>r) return 0;

    else if(l==r&&arr[l]!=0) return 1;

    else if(l==r&&arr[l]==0) return 0;

    int ans=(r-l)+1;

    int mn_indx;

    int mx=INT_MAX;

    for(int i=l;i<=r;i++) if(mx>arr[i]) {mx=arr[i];mn_indx=i;}
    int mn=arr[mn_indx];

    for(int i=l;i<=r;i++) arr[i]=arr[i]-mn;

    int l1 = mn_indx-1;
    int r1 = mn_indx+1;

    ans=min(ans,segment_tree(l,l1)+segment_tree(r1,r)+mn);

   // cout<<ans<<" "<<l<< " "<<r<<endl;

    return ans;
}

int main()

{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ll res=segment_tree(1,n);
    cout<<res<<endl;
    return 0;
}
