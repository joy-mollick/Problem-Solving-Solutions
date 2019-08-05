 #include<bits/stdc++.h>

 using namespace std;

 const int mx=101;
 int parent[mx];
 int rnk[mx]={0};
 int freq[mx]={0};

 int Find(int x)
 {
     if(x!=parent[x])
        parent[x]=Find(parent[x]);

     return parent[x];
 }

 void Union(int x,int y)

 {
     int a=Find(x);
     int b=Find(y);

     if(a==b) return;

     if(rnk[a]<rnk[b])
     {
         parent[a]=b;
     }
     else
       {
           parent[b]=a;
           if(rnk[a]==rnk[b])
            rnk[b]++;
       }
 }

 int main()

 {
     int n,m;
     int no_language=0,count=0;
     for(int i=0;i<=mx;i++)
     {
         parent[i]=i;
     }
     cin>>n>>m;
     int u,v,k;
     for(int i=0;i<n;i++)
     {
         cin>>k;
         if(k==0)
         {
             no_language++;
             continue;
         }
         cin>>u;// first elements of k elements
         freq[u]++;
         for(int j=1;j<k;j++)
         {
             cin>>v;
             freq[v]++;
             Union(u,v);// make set
         }
     }
     int ans=0;
     for(int i=1;i<=m;i++)
     {
         if(freq[i]==0) count++;
         else if(parent[i]==i)
         {
             ans++;
         }
     }
     ans=ans-1;
     if(count==m) cout<<n<<endl;
     else
     {
        cout<<ans+no_language<<endl;
     }
     return 0;
 }
