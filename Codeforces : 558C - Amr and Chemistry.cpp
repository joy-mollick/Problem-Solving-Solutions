/// Codeforces : 558C - Amr and Chemistry.
/// Category : number theory + bfs + shortest path.

/// we will use bfs.
/// multiply by two (2) increase position of bit.
/// divide by two(2) decrease position of bit.
/// position will not of course cross log2(100000)

#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

const int mx= 2000001;

int times[mx];
int ans[mx];

queue<pair<pair<int,int>,int> >pq;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
            cin>>arr[i];
            pq.push(make_pair(make_pair(arr[i],0),0));
    }

    while(!pq.empty())
    {
        int num=pq.front().first.first;
        int previous=pq.front().first.second;
        int steps=pq.front().second;
        pq.pop();
        /// this num will be counted
        times[num]++;
        ans[num]+=steps;
        if(num*2<=200000 && num*2!=previous) pq.push(make_pair(make_pair(2*num,num),steps+1));
        if(num/2>0 && num/2!=num && num/2!=previous) pq.push(make_pair(make_pair(num/2,num),steps+1));
    }

    int res=INT_MAX;

    for(int i=1;i<=200000;i++)
    {
        /// every number touches this state (i)
        if(times[i]==n)
        {
            res=min(res,ans[i]);
        }
    }

    cout<<res<<endl;

    return 0;
}
