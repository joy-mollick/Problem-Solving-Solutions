#include<bits/stdc++.h>

using namespace std;


int main()

{
    int n,m,a,b;
    cin>>n>>m;
    int arr[n+1]={0};
    while (m--)
    {
        cin>>a>>b;
        arr[a]++;
        arr[b]++;
    }
    int centre;
   for(int j=1;j<=n;j++)
   {

       if(arr[j]==0)
       {

           centre=j;
       }
   }
   cout<<(n-1)<<endl;
   for(int i=1;i<=n;i++)
   {
       if(i!=centre)
       cout<<i<<" "<<centre<<endl;
   }
}
