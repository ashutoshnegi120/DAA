#include "bits/stdc++.h"

using namespace std;

typedef struct Edge{
    int src, dest,weight;
}edge;

typedef struct Graph{
    int v,e;
    edge* edges;
}graph;

graph* createGraph(int v,int e)
{
    graph* g = new graph;
    g->v = v; g->e = e;
    g->edges = new edge[g->e];
    return g;
}

bool isNegCycleBellmanFord(graph* graph, int src)
{
    int v = graph->v;
    int e = graph->e;
    int dist[v];

    for(int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;


    for(int i = 0; i < v-1; i++)
    {
        for(int j = 0; j < e; j++)
        {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for(int i = 0; i < e; i++)
    {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
    }
    return false;
}

int main()
{
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    graph* graph = createGraph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;
    graph->edges[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edges[5].src = 3;
    graph->edges[5].dest = 2;
    graph->edges[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edges[6].src = 3;
    graph->edges[6].dest = 1;
    graph->edges[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edges[7].src = 4;
    graph->edges[7].dest = 3;
    graph->edges[7].weight = -3;
 
    if (isNegCycleBellmanFord(graph, 0))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}