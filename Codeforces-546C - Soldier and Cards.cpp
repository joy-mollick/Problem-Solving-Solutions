#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;
typedef pair<int,int> pi;


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,d,k1,k2;
    cin>>n;
    queue<int>a;
    queue<int>b;
    cin>>k1;
    while(k1--)
    {
        cin>>d;
        a.push(d);
    }
    cin>>k2;
    while(k2--)
    {
        cin>>d;
        b.push(d);
    }
    int win;
    int count=0;
    while(true)
    {
        int frst=a.front();
        a.pop();
        int scnd=b.front();
        b.pop();
        count++;
        if(frst>scnd)
        {
            a.push(scnd);
            a.push(frst);
        }
        else
        {
            b.push(frst);
            b.push(scnd);
        }
        if(a.empty())
        {
            win=2;
            break;
        }
        if(b.empty())
        {
            win=1;
            break;
        }
        if(count>100000)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<count<<" "<<win<<endl;
}

