#include <bits/stdc++.h>

using namespace std;

int findMinKey(int keys[], bool inMST[]){
    int min = INT_MAX;
    int vertex = 0;

    for (int i = 0; i < 6; i++){
        if (!inMST[i] && keys[i] < min){
            min = keys[i];
            vertex = i;
        }
    }

    return vertex;
}

void prim(int source, int graph[6][6], int parent[]){

    int keys[6];

    bool inMST[6];

    for (int j = 0; j < 6; j++){
        inMST[j] = false;
        keys[j] = INT_MAX;
    }

    keys[source] = 0;
    parent[source] = -1;

    for (int edges = 0; edges < 5; edges++){
        int u = findMinKey(keys, inMST);
        inMST[u] = true;

        for (int v = 0; v < 6; v++){
            if (graph[u][v] && !inMST[v] && graph[u][v] < keys[v]){
                parent[v] = u;
                keys[v] = graph[u][v];
            }
        }
    }
}

int main()
{
    int parent[6];

    int graph[6][6] = {
    {0,3,0,0,0,1}, 
    {3,0,2,1,10,0}, 
    {0,2,0,3,0,5}, 
    {0,1,3,0,5,0}, 
    {0,10,0,5,0,4}, 
    {1,0,5,0,4,0}
    };

    // We can set source here
    int source = 0;
    prim(source, graph, parent);

    for (int v = 0; v < 6; v++){
        if (v == source)    continue;
        cout << "Edge -> "<< parent[v] << " - " << v  << "\tWeight = " << graph[parent[v]][v] << endl; 
    }
    return 0;
}
