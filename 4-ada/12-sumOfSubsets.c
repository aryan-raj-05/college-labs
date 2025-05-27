#include <stdio.h>
#include <time.h>

#define MAX 20

int w[MAX], x[MAX], n, m;

void sumOfSub(int s, int k, int r) {
    if (k > n) return;
    x[k] = 1;

    if (s + w[k] == m) {
        printf("Solution vector is: ");
        for (int i = 1; i <= n; i++) printf("%d ", x[i]);
        printf("\n");
    } else if (s + w[k] + w[k + 1] <= m) {
        sumOfSub(s + w[k], k + 1, r - w[k]);
    }

    x[k] = 0;
    if (s + r - w[k] >= m && k + 1 <= n && s + w[k + 1] <= m)
        sumOfSub(s, k + 1, r - w[k]);
}

int main() {
    int sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the set: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
        x[i] = 0;
    }

    printf("Enter the max subset value: ");
    scanf("%d", &m);

    clock_t start = clock();
    sumOfSub(0, 1, sum);
    clock_t end = clock();

    printf("Time taken: %f\n", (end - start) / (double) CLOCKS_PER_SEC);
}