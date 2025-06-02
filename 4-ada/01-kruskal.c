#include <stdio.h>
#include <time.h>

#define MAX 10
#define INF 999

void _union(int s[], int i, int j) { s[i] = j; }

int find(int s[], int i) {
    while (s[i] != i) i = s[i];
    return i;
}

void kruskal(int graph[MAX][MAX], int vertices) {
    int s[MAX];         // s = union-find data structure,
    int tree[MAX][2];   // tree = stores the vertices' index that are connected,
    int sum = 0;        // sum = total sum of spanning tree, 
    int count = 0;      // count = current vertices counted,
    int k = 0;          // k = to iterate over the tree,

    // Initialize DSU
    for (int i = 0; i < vertices; i++) s[i] = i;

    // [0] while count is less than |V| - 1
    // [1] find the minimum weight (not 0)
    // [2] if (min = 999) => break from loop
    // [3] set corresponding entry in graph to 999
    // [4] if the index are not connected, connect them
    // [5] add the weight to final sum
    // [6] increment the count
    while (count < vertices - 1) {
        int u = -1, w = -1;
        int min = INF;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) 
                if (graph[i][j] < min && graph[i][j] != 0) {
                    min = graph[i][j];
                    u = i; w = j;
                }
        }
        if (min == INF) break;

        graph[u][w] = INF;
        graph[w][u] = INF;

        if (find(s, u) != find(s, w)) {
            _union(s, find(s, u), find(s, w));
            tree[k][0] = u;
            tree[k++][1] = w;
            sum += min;
            count++;
        }
    }

    // print the result
    if (count != vertices - 1) {
        printf("Spanning tree doesn't exist\n");
        return;
    }

    printf("Cost of spanning tree: %d\n", sum);
    printf("spanning tree is shown below: \n");
    for (int i = 0; i < vertices - 1; i++) {
        printf("%d -> %d\n", tree[i][0], tree[i][1]);
    }
}

int main() {
    int graph[MAX][MAX];

    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix: \n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    clock_t start = clock();
    kruskal(graph, n);
    clock_t end = clock();

    printf("Time taken in sec is %f\n", (end - start) / (double) CLOCKS_PER_SEC);
}