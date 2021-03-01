

/// Codeforces 13C - Sequence

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res;
priority_queue<int> pq;
main()
{
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        int x; cin >> x;
        if(!pq.empty() && pq.top() > x)
        {
            res += pq.top() - x;
            pq.pop();
            pq.push(x);
        }
        pq.push(x);
    }
    cout << res;
      return 0;

}
