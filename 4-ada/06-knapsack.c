#include <stdio.h>

#define MAX 10
// w[10] => weight of each objects
// value[] => value of each object
// b[] => marks if item at index i is taken or not
int w[MAX], value[MAX], b[MAX];
int v[MAX][MAX]; // MEMOIZATION TABLE

int max(int a, int b) { return (a > b) ? a : b; }

int knap(int i, int j) {
    if (i == 0 || j == 0) v[i][j] = 0;
    if (v[i][j] != -1) return v[i][j];
    if (j < w[i]) 
        v[i][j] = knap(i - 1, j); // exclude the item
    else
        v[i][j] = max(
            knap(i - 1, j), // exclude the item
            value[i] + knap(i - 1, j - w[i]) // include the item
        );
    return v[i][j];
}

void optimal(int i, int j) {
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            printf("Item %d included\n", i);
            b[i] = 1;
            j -= w[i];
        }
        i--;
    }
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the values: ");
    for (int i = 1; i <= n; i++) scanf("%d", &value[i]);

    printf("Enter the weights: ");
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= capacity; j++)
            v[i][j] = -1;

    int profit = knap(n, capacity);
    printf("Profit: %d\nOptimal Subset is:\n", profit);
    optimal(n, capacity);

    printf("The solution vector is: ");
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    printf("\n");
}