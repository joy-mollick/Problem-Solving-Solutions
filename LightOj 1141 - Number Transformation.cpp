
/// Time- 0.005s
///  LightOj 1141 - Number Transformation 
///  BFS

#include<bits/stdc++.h>

using namespace std;

int SRC, DEST;
vector <int> primef[1001];
void primefactor( int n)
{
    int num = n;
    int fact = 2;
    int fct = 0 ;
    while(n > 1)
    {
        fct = 0;
        while( n % fact == 0 )
        {
            fct=fact;
            n /= fact;
        }
        if(fct) primef[num].push_back(fct);
        fact += 1;
    }
    if( fct == num ) primef[num].clear();
}
int bfs( )
{
    int dist[1001];
    memset(dist, -1, sizeof(dist));
    dist[SRC] = 0;
    queue <int> q;
    q.push(SRC);
    int from, to;
    while( !q.empty() ){
        from = q.front();
        q.pop();
        for( int i = 0; i < (int) primef[from].size(); i++ ){
            to = from + primef[from][i];
            if( to<=DEST && dist[to]==-1 )
            {
                q.push(to);
                dist[to] = dist[from] + 1;
                if(to==DEST) return dist[DEST];
            }
        }
    }
    return dist[DEST];
}

int main(){

    int T;
    int caso = 0;
   //freopen("input.txt", "r", stdin);
   for( int i = 2; i <= 1000; i++ ) primefactor(i);
   scanf("%d", &T);
    while( T-- ){
        caso++;
        scanf("%d %d", &SRC, &DEST);
        printf("Case %d: %d\n", caso, bfs());
    }

    return 0;
}
