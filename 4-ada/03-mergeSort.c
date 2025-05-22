#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000
int aux[MAX];

void merge(int nums[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) {
        if (nums[j] <= nums[i]) aux[k++] = nums[j++];
        else aux[k++] = nums[i++];
    }

    while (i <= mid) aux[k++] = nums[i++];
    while (j <= hi) aux[k++] = nums[j++];

    for(int idx = lo; idx <= hi; idx++) {
        nums[idx] = aux[idx];
    }
}

void mergesort(int nums[], int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergesort(nums, lo, mid);
    mergesort(nums, mid + 1, hi);
    merge(nums, lo, mid, hi);
}

int main() {
    int nums[MAX];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // srand(time(NULL));

    printf("Array elements are: ");
    for(int i = 0; i < n; i++) {
        nums[i] = rand() % 1000;
        printf("%d ", nums[i]);
    }

    clock_t start = clock();
    mergesort(nums, 0, n - 1);
    clock_t end = clock();

    printf("\nElements of array after sorting: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\nTime taken = %f\n", (end - start) / (double) CLOCKS_PER_SEC);
}