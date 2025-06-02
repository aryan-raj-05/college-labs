#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 999

int numNodes, startNode;
int selected[20], distance[20], parent[20];
int weight[20][20], result[20][2];

// Function to find the vertex with the minimum distance
int findMin() {
    int minIndex = -1;
    for (int i = 1; i <= numNodes; i++) {
        if (!selected[i]) {
            if (minIndex == -1 || distance[i] < distance[minIndex]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

// Prim's algorithm implementation
void prims() {
    int totalCost = 0, edgeCount = 0;

    for (int i = 1; i <= numNodes; i++) {
        selected[i] = 0;
        distance[i] = INF;
        parent[i] = 0;
    }

    distance[startNode] = 0;

    for (int k = 1; k <= numNodes; k++) {
        int u = findMin();
        if (u == -1) break; // No more reachable nodes

        selected[u] = 1;

        // Record the edge
        if (parent[u] != 0) {
            result[edgeCount][0] = parent[u];
            result[edgeCount][1] = u;
            totalCost += weight[u][parent[u]];
            edgeCount++;
        }

        // Update distances
        for (int v = 1; v <= numNodes; v++) {
            if (weight[u][v] != INF && !selected[v] && weight[u][v] < distance[v]) {
                distance[v] = weight[u][v];
                parent[v] = u;
            }
        }
    }

    // Output
    if (edgeCount != numNodes - 1) {
        printf("Spanning tree doesn't exist (graph is disconnected)\n");
    } else {
        printf("Minimum cost spanning tree:\n");
        for (int i = 0; i < edgeCount; i++) {
            int from = result[i][0];
            int to = result[i][1];
            printf("%d ---> %d = %d\n", from, to, weight[to][from]);
        }
        printf("Total cost of spanning tree: %d\n", totalCost);
    }
}

int main() {
    clock_t startTime, endTime;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            scanf("%d", &weight[i][j]);
        }
    }

    printf("Enter the starting node (1 to %d): ", numNodes);
    scanf("%d", &startNode);

    startTime = clock();
    prims();
    endTime = clock();

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Time taken: %.4f seconds\n", timeTaken);

    return 0;
}
