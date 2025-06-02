#include <stdio.h>
#include <time.h>
#define INF 999
#define MAX 20

int graph[MAX][MAX];// Adjacency matrix representation of the graph
int n;              // Number of vertices
int dist[MAX];      // Distance from source
int visited[MAX];   // Visited vertices
int parent[MAX];    // Parent vertices for path reconstruction

int findMin() {
    int minIndex = -1;
    for (int i = 0; i < n; i++) 
        if (!visited[i] && (minIndex == -1 || dist[i] < dist[minIndex])) 
            minIndex = i;
    return minIndex;
}

void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = findMin(); 
        visited[u] = 1; 
        for (int v = 0; v < n; v++) 
            if (graph[u][v] != INF && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
}

void printPath(int vertex) {
    if (vertex == -1) return;
    printPath(parent[vertex]);
    printf("%d ", vertex);
}

void printSolution() {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) 
        printf("%d \t\t %d\n", i, dist[i]);
    
    printf("\nPaths from source:\n");
    for (int i = 0; i < n; i++) {
        printf("Path to %d: ", i);
        printPath(i);
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (999 for no edge):\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]);
        
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    clock_t start = clock();
    dijkstra(source);
    clock_t end = clock();
    
    printSolution();
    printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}