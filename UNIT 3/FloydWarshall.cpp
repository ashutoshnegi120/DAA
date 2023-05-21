#include<bits/stdc++.h>

using namespace std;

#define v 4
#define INF 999999

void printSolution(int dist[][v]);

bool negCyclefloydWarshall(int graph[][v])
{
    int dist[v][v],i,j,k;

    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            dist[i][j] = graph[i][j];

    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        if(dist[i][i] < 0)
            return true;
        return false;
    }
}

int main()
{     
    int graph[v][v] = { {0   , 1   , INF , INF},
                        {INF , 0   , -1  , INF},
                        {INF , INF , 0   ,  -1},
                        {-1  , INF , INF ,   0}};
     
    if (negCyclefloydWarshall(graph))
       cout << "Yes";
    else
       cout << "No";

    return 0;
}