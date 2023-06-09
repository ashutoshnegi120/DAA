#include <bits/stdc++.h>
using namespace std;



int main()
{
	// n is the number of vertices
	// m is the number of edges
	int n, m;
	cin >> n >> m;
	int adjMat[n + 1][n + 1];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjMat[u][v] = 1;
		adjMat[v][u] = 1;
		// for a directed graph with an edge pointing from u
		// to V,we just assign adjMat[u][v] as 1
	}
    for(int i = 0; i < n; i++) 
    {
        cout<< i << " - ";
        for(int j = 0; j < m; j++)
        {
            if(adjMat[i][j] == 1)
            {
                cout<< j << " ";
            }
        }
        cout<<endl;
    }
	return 0;
}
