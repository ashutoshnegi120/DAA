#include <bits/stdc++.h>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjacencyList;
    bool isCyclicUtil(int v, bool visited[], bool* recStack);

public:
    Graph(int numVertices);
    void AddEdge(int v, int w);
    bool IsCyclic();
};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjacencyList = new list<int>[numVertices];
}

void Graph::AddEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool* recStack)
{
    if (visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator it;
        for (it = adjacencyList[v].begin(); it != adjacencyList[v].end(); ++it) {
            if (!visited[*it] && isCyclicUtil(*it, visited, recStack))
                return true;
            else if (recStack[*it])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::IsCyclic()
{
    bool* visited = new bool[numVertices];
    bool* recStack = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
    }
    return false;
}

int main()
{
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    if (g.IsCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
