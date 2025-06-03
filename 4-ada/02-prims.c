#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 999
#define MAX 20

int numNodes, startNode;
int weight[MAX][MAX], selected[MAX], dist[MAX], parent[MAX], result[MAX][2];

int findMin() {
    int minIdx = -1;
    for (int i = 1; i <= numNodes; i++)
        if (!selected[i] && (minIdx == -1 || dist[i] < dist[minIdx]))
            minIdx = i;
    return minIdx;
}

void prims() {
    for (int i = 1; i <= numNodes; i++) {
        dist[i] = INF;
        selected[i] = 0;
        parent[i] = 0;
    }
    dist[startNode] = 0;

    int totalCost = 0, edgeCount = 0;

    for (int i = 1; i <= numNodes; i++) {
        int u = findMin();
        if (u == -1) break;
        selected[u] = 1;

        if (parent[u]) {
            result[edgeCount][0] = parent[u];
            result[edgeCount][1] = u;
            totalCost += weight[u][parent[u]];
            edgeCount++;
        }

        for (int v = 1; v <= numNodes; v++) {
            if (!selected[v] && weight[u][v] < dist[v]) {
                dist[v] = weight[u][v];
                parent[v] = u;
            }
        }
    }

    if (edgeCount != numNodes - 1) {
        printf("Spanning tree doesn't exist (graph is disconnected)\n");
        return;
    }

    printf("Minimum cost spanning tree:\n");
    for (int i = 0; i < edgeCount; i++) {
        int u = result[i][0], v = result[i][1];
        printf("%d ---> %d = %d\n", u, v, weight[v][u]);
    }
    printf("Total cost: %d\n", totalCost);
}

int main() {
    clock_t start = clock();

    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter adjacency matrix (%d = INF):\n", INF);
    for (int i = 1; i <= numNodes; i++)
        for (int j = 1; j <= numNodes; j++)
            scanf("%d", &weight[i][j]);

    printf("Enter starting node (1 to %d): ", numNodes);
    scanf("%d", &startNode);

    prims();

    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.4f seconds\n", time);

    return 0;
}
