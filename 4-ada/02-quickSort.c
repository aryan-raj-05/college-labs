#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000
int nums[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int lo, int hi) {
    int key = nums[lo];
    int i = lo, j = lo + 1;
    while (j <= hi) {
        if (nums[j] < key) swap(&nums[++i], &nums[j]);
        j++;
    }
    swap(&nums[i], &nums[lo]);
    return i;
}

void quicksort(int nums[], int lo, int hi) {
    if (lo > hi) return;
    int mid = partition(nums, lo, hi);
    quicksort(nums, lo, mid - 1);
    quicksort(nums, mid + 1, hi);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) nums[i] = rand() % 1000;
    printf("The array is: \n");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);

    clock_t start = clock();
    quicksort(nums, 0, n - 1);
    clock_t end = clock();

    printf("\nThe sorted array is: \n");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);

    printf("\nTime taken is %f\n", (end - start) / (double) CLOCKS_PER_SEC);
}