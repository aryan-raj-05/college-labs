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

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        swap(&arr[i], &arr[min]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) nums[i] = rand() % 1000;

    printf("The array is: \n");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    
    clock_t start = clock();
    selection_sort(nums, n);
    clock_t end = clock();

    printf("\nSorted Array is: \n");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\nTime taken is %f\n", (end - start) / (double) CLOCKS_PER_SEC);

    return 0;
}