#include<bits/stdc++.h>

const long mod=100000;

using namespace std;

int main()
{
    long n,key,num,a;
    cin>>n>>key;
    cin>>num;
    vector<long>keylist;
    while(num--)
    {
        cin>>a;
        keylist.push_back(a);
    }
    queue<long>q;
    q.push(n);
    long count[100001];
    for(int i=0;i<=100000;i++)
    {
        count[i]=-1;// nonvisited means -1,it's not possible to make i
    }
    count[n]=0;
    while(!q.empty())
    {
        long nw=q.front();
        if(key==nw)
        {
            break; // done , we have found
        }
        q.pop();
        for(int i=0;i<keylist.size();i++)
        {
            long now=(nw*keylist[i])%mod;
            if(count[now]==-1)
            {
                q.push(now);
                count[now]=count[nw]+1;
            }
        }
    }
    cout<<count[key]<<endl;
    return 0;
}
