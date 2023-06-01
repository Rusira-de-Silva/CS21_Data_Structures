#include <bits/stdc++.h>

using namespace std;

// function to find minimum distance vertex
int findMinDis(int dist[], bool visited[]){
    int min = INT_MAX;
    int vertex = 0;

    for (int i = 0; i < 6; i++){
        if (!visited[i] && dist[i] < min){
            min = dist[i];
            vertex = i;
        }
    }

    return vertex;
}

// Dijkstra's Algorithm
void dijkstra(int graph[6][6], int source, int dist[]){

    // array to mark the visited nodes
    bool visited[6];

    // variable to calculate distance
    int calDistance;

    // setting initial distance and visit status
    for (int i = 0; i < 6; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // setting initial distance of source to zero to pick it first
    dist[source] = 0;

    // max length of shortest distance can be V-1
    for (int edges = 0; edges < 5; edges++){
        int u = findMinDis(dist, visited);
        visited[u] = true;

        // update distance if calculated distance < current distance 
        for (int v = 0; v < 6; v++){
            calDistance = graph[u][v] + dist[u];
            if (graph[u][v] && !visited[v] && calDistance < dist[v]){
                dist[v] = calDistance;
            }
        }
    }
}

// Function to calculate Average time
void printAverage(int graph[6][6], int dist[]){
    double totalTime;
    double avg = 0;
    for (int city = 0; city < 6; city++){
        totalTime = 0;
        dijkstra(graph, city, dist);
        for (int i = 0; i < 6; i++)  totalTime += dist[i];
        avg = totalTime / 6.0;
        cout << "From city - " << city << "\taverage time -> " << avg << endl;
    }

}

int main()
{
    // Adjacency matrix
    int graph[6][6] = {
    {0,10,0,0,15,5}, 
    {10,0,10,30,0,0}, 
    {0,10,0,12,5,0}, 
    {0,30,12,0,0,20}, 
    {15,0,5,0,0,0}, 
    {5,0,0,20,0,0}
    };

    // Distance array
    int distance[6];

    // We can get shortest time from a city like below (for example source = 0)
    dijkstra(graph, 0, distance);

    // Then we can print minimum distances from source
    for (int city = 0; city < 6; city++)    cout << "To City -> " << city << " = "<< distance[city] << endl;

    cout << '\n';
    cout << '\n';

    // Printing average distances from each city
    printAverage(graph, distance);

    return 0;
}
