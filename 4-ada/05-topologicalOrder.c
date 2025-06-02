#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int graph[MAX][MAX];
int inDegree[MAX];
int flag[MAX];

// [1] calculate the in-degree of each vertex
// [2] find all vertices with in-degree 0
// [3] remove these vertices from the graph and update in-degrees
// [4] repeat until all vertices are processed or no vertices with in-degree 0 are left
// [5] if all vertices are processed, print the topological order
// [6] if not all vertices are processed and no vertices with in-degree 0 are left, the graph is cyclic
// [7] if the graph is cyclic, print an error message
void topology(int n) {
    for(int i = 0; i < n; i++) flag[i] = 0;
    printf("\nTopological ordering of the given graph is:\n");

    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) 
            inDegree[i] += graph[j][i];
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0 && flag[i] == 0) {
                printf("%d ", i);
                count++;
                flag[i] = 1;
                found = 1;
                for (int j = 0; j < n; j++) 
                    if (graph[i][j] == 1) inDegree[j]--;
            }
        }

        if (!found) {
            printf("\nTopological ordering not possible\n");
            printf("\nThe given graph is cyclic\n");
            exit(0);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]);
        
    clock_t start = clock();
    topology(n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_spent);
    return 0;
}