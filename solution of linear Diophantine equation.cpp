/* Number of solutions of euations of type ax+by=d */

#include <bits/stdc++.h>
using namespace std;
#define AB_BHI_NI_DEGI                \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

int g, x, y;
void EXT_GCD(int a, int b)
{
    if (b == 0)
    {
        g = a;
        x = 1;
        y = 0;
    }
    else
    {
        EXT_GCD(b, a % b);
        int temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}
void solve()
{
    int a, b, d;
    cin >> a >> b >> d;
    EXT_GCD(a, b);
    if (d % g)
    {
        cout << "0\n";
        return;
    }
    double db = (1.0 * d) / (1.0 * b);
    double da = (1.0 * d) / (1.0 * a);
    int l = ceil(double(-x * 1.0 * db));
    int r = floor(double(y * 1.0 * da));
    if (l <= r)
        cout << r - l + 1 << "\n";
    else
        cout << "0\n";
}
int32_t main()
{
    AB_BHI_NI_DEGI
    int Test = 1;
    //cin >> Test;
    int itr = 1;
    while (Test--)
    {
        //cout << "Case #" << itr++ << ": ";
        solve();
    }
    return 0;
}
/*

    */
