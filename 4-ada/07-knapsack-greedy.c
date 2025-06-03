#include <stdio.h>

#define MAX 100

void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void knapsack(int n, int item[], float weight[], float profit[], float capacity) {
    float ratio[MAX], x[MAX];
    float totalProfit = 0.0f;
    float remaining = capacity;

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(&ratio[i], &ratio[j]);
                swap(&weight[i], &weight[j]);
                swap(&profit[i], &profit[j]);
                swapInt(&item[i], &item[j]);
            }
        }
    }

    // Initialize fractions
    for (int i = 0; i < n; i++)
        x[i] = 0.0f;

    // Fill the knapsack
    for (int i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            x[i] = 1.0f;
            totalProfit += profit[i];
            remaining -= weight[i];
        } else {
            x[i] = remaining / weight[i];
            totalProfit += x[i] * profit[i];
            break;  // Knapsack is full
        }
    }

    // Output result
    printf("\nResult vector (fractions of items taken):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", item[i], x[i]);
    }
    printf("Maximum profit: %.2f\n", totalProfit);
}

int main() {
    int n, item[MAX];
    float weight[MAX], profit[MAX], capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the item ID, weight, and profit for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%f%f", &item[i], &weight[i], &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    knapsack(n, item, weight, profit, capacity);

    return 0;
}
