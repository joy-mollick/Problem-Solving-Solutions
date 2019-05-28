#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<long,long>m;
        while(n--)
        {
            cin>>a;
            m[a]++;
        }
        map<long,long>::iterator it=m.begin();
        long ans=0;
        for(it;it!=m.end();it++)
        {
            long m=(it->second);
            ans=ans+((m*(m+1))/2);
        }
        cout<<ans<<endl;
    }


}
