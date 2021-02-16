
/// Codeforces 586D - Phillip and Trains 
/// DFS + thinking 

#include <bits/stdc++.h>

using namespace std;

int n,k,srcx,srcy;
char grid[10][120];
bool flg;
int vis[10][120];

bool judge(int x,int y){
    return (x >= 0 && x < 3 && (grid[x][y] == '.' || grid[x][y] == 's'));
}

void man_go(int x,int y)
{
	vis[x][y] = 1;
    if (y >= n - 1){
        flg = true;
        return;
    }
    if (flg) return;
    /// he will be caught
    if (!judge(x,y+1)) return;
    if (judge(x,y+1) && judge(x,y+2) && judge(x,y+3) && !vis[x][y+3]) {
        man_go(x,y+3);
    }
    if (judge(x+1,y+1) && judge(x+1,y+2) && judge(x+1,y+3) && !vis[x+1][y+3]) {
        man_go(x+1,y+3);
    }
    if (judge(x-1,y+1) && judge(x-1,y+2) && judge(x-1,y+3) && !vis[x-1][y+3]) {
        man_go(x-1,y+3);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	memset(vis,0,sizeof(vis));
        flg = false;
        cin >> n >> k;
        for (int i = 0;i < 3;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 's') srcx = i,srcy = j;
            }
            /// for extra memory of dfs
            for (int j = n;j < 115;j++) grid[i][j] = '.';
        }
        man_go(srcx,srcy);
        if (flg) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
