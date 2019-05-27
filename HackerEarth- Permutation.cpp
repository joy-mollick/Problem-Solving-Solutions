#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    cin>>n;
    string asol="";
    for(int i=0;i<n;i++)
    {
        cin>>a;
        asol+=(a+'0');
    }

    string our_destination=asol;
    sort(our_destination.begin(),our_destination.end());
    //our_destination is our destination where we have to reach
    map<string,int>m;
    m[asol]=0;//it already given , so to reach it 0 operation
    queue<string>q;
    q.push(asol);// we will start from this given input
    while(!q.empty())
    {
        string prev=q.front();
        q.pop();
        if(prev==our_destination)
        {
            cout<<m[prev]<<endl;
            break;
        }
        for(int i=2;i<=n;i++)
        {
            string now=prev;
            reverse(now.begin(),now.begin()+i);// we will reverse(first i)numbers
            if(m.find(now)==m.end())// if it doesn't exist then we will operate over here
            {
                m[now]=m[prev]+1;
                q.push(now);//we will operate other reverse over this later ,so push into q
            }
        }
    }

    return 0;
}
