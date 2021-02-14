
/// Codeforces 466E - Information Graph 
/// Nice one ,dsu 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx=100100;

int father[mx];
int boss[mx];

vector<int>sign;
vector<int>sign_fa;

int find_fat(int x)
{
    	if(x==father[x]) return x;
	    return father[x]=find_fat(father[x]);
}


int main()

{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<mx;i++) father[i]=i,boss[i]=i;
    int typ,a,b;

    while(m--)
    {
        cin>>typ;
        if(typ==1)
        {
            cin>>a>>b;
            boss[a]=b;
            father[a]=b;
        }

        else if(typ==2)
        {
            cin>>a;
            sign.push_back(a);
            sign_fa.push_back(find_fat(a));
        }

        else if(typ==3)
        {
            cin>>a>>b;
            b--;
            int frst=sign[b];
            int secnd=sign_fa[b];
            bool flag=false;

            while(true)
            {
                /// a man from cycle hold this
                if(frst==a) {flag=true;break;}
                /// no sign
                if(frst==secnd) break;
                frst=boss[frst];
            }

            if(flag) puts("YES");
            else puts("NO");
        }
    }

    return 0;
}
