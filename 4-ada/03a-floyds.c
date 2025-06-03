#include <stdio.h>
#include <time.h>

#define MAX 10
#define INF 999

int min(int a, int b) { return a < b ? a : b; }

void floyds(int graph[MAX][MAX], int v) {
    for (int k = 0; k < v; k++) 
        for (int i = 0; i < v; i++) 
            for (int j = 0; j < v; j++) 
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    int graph[MAX][MAX];

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    clock_t start = clock();
    floyds(graph, n);
    clock_t end = clock();

    printf("Time taken: %f\n", (end - start) / (double) CLOCKS_PER_SEC);
    printf("The resultant path matrix is:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}