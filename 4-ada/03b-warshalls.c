#include <stdio.h>
#include <time.h>

#define MAX 50
#define INF 999

void warshalls(int graph[MAX][MAX], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
}

int main() {
    int graph[MAX][MAX];
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    clock_t start = clock();
    warshalls(graph, n);
    clock_t end = clock();

    printf("The transitive closure is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    printf("The time taken by warshall's is: %f\n", (end - start) / (double) CLOCKS_PER_SEC);
}