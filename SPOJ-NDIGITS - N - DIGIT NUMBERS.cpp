#include <bits/stdc++.h>

using namespace std;

int main()

{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"10"<<endl;
        }
        else{
            n=n-1;
            cout<<"9";
            while(n--)
            {
                cout<<"0";
            }
            cout<<endl;
        }
    }
}
