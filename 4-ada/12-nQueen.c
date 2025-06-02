#include <stdio.h>
#include <stdlib.h>

int solutionCount = 0;

void printSolution(int n, int q[]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%c\t", (q[i] == j) ? 'Q' : 'x');
        printf("\n");
    }
    printf("\n");
}

int canPlace(int q[], int row) {
    for (int i = 1; i < row; i++) {
        if (q[i] == q[row] || abs(q[i] - q[row]) == abs(i - row))
            return 0;
    }
    return 1;
}

void solveNQueens(int n) {
    int q[20], row = 1;
    q[row] = 0;

    while (row > 0) {
        q[row]++;
        while (q[row] <= n && !canPlace(q, row)) q[row]++;

        if (q[row] <= n) {
            if (row == n) {
                printf("Solution %d:\n", ++solutionCount);
                printSolution(n, q);
            } else {
                row++;
                q[row] = 0;
            }
        } else {
            row--;
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    solveNQueens(n);
    return 0;
}
