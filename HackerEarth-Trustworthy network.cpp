/*
First One is , this is directional edge given . Now , when u will go from source ( s) to destination (e) . 
Suppose u have gone such path ( s -> u -> v-> e ) now total cost will be , 
when u will go from s to u , cost[s][u] and (for acknowledging ) cost of back from u to s cost[u][s] ,
for only (s->u)  cost[s][u] + cost[u][s]  !!  Now for , ( u->v ) cost[u][v] + cost[v][u] !! Such as ......
cost[s][u] + cost[u][s] + cost[u][v] + cost[v][u] +cost[v][e]+cost[e][v] will be our answer . 
Answer should be minimized . We have to use floyd warshall algorithm to find shortest path of any pair . 
Then after doing this,make the cost of every graph[u][v] to graph[u][v] + dist[v][u],where dist has been found by floyd wrshall .
Now each graph[u][v] holds the value of graph[u][v] itself and dist[v][u] summation ...........
Now run again floyd warshall to find shortest path from source to destination ................... 
*/
#include<bits/stdc++.h>

using namespace std;

const int N=303;

int graph[N][N];
int dist[N][N];


int main()

{
    int n,m,u,v,source,destination,w;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            graph[i][j]=dist[i][j]=(i==j)?0:INT_MAX; // distance from i to i or j to j is zero (0)
        }
    }

    cin>>n>>m>>source>>destination;

    while(m--)
    {
        cin>>u>>v>>w;
        graph[u][v]=dist[u][v]=w;
    }


    // Here we will use floyd warshall algo , because we need the shortest path of any two pairs for building our algo
    // floyd warshall algorithm to find the shortest path between any pairs { i,j } -> dist[i][j]

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX)
                continue;

                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    // Now , the graph[i][j] should be the equal to graph[i][j] + dist[j][i]

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]!=INT_MAX && dist[j][i]!=INT_MAX)
                graph[i][j]=graph[i][j]+dist[j][i];

                else
                graph[i][j]=INT_MAX; // if there is no way back from j to i dist[j][i]=inf then also graph[i][j] inf
        }
    }

    // Now , the value of graph edges graph[i][j] has been changed ,nw finding the shortest distance from source to destination ,I will use floyd warshall because of adjacent matrix

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graph[i][k]==INT_MAX || graph[k][j]==INT_MAX)
                continue;

                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

    cout<<(graph[source][destination]==INT_MAX?-1:graph[source][destination])<<endl;


    return 0;
}
