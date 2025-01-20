#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the priority queue

typedef struct {
    int data[MAX_SIZE];
    int size; // Number of elements in the priority queue
} PriorityQueue;

// Function prototypes
void initPriorityQueue(PriorityQueue *pq);
void insert(PriorityQueue *pq, int value);
int extractMax(PriorityQueue *pq);
int getMax(PriorityQueue *pq);
void heapifyDown(PriorityQueue *pq, int index);
void heapifyUp(PriorityQueue *pq, int index);

// Initialize the priority queue
void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Insert an element into the priority queue
void insert(PriorityQueue *pq, int value) {
    if (pq->size == MAX_SIZE) {
        printf("Priority queue is full!\n");
        return;
    }
    pq->data[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

// Extract the maximum element from the priority queue
int extractMax(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty!\n");
        return -1;
    }
    int maxValue = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return maxValue;
}

// Get the maximum element without removing it
int getMax(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty!\n");
        return -1;
    }
    return pq->data[0];
}

// Heapify up to maintain the max-heap property
void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && pq->data[index] > pq->data[parent]) {
        // Swap the current element with its parent
        int temp = pq->data[index];
        pq->data[index] = pq->data[parent];
        pq->data[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify down to maintain the max-heap property
void heapifyDown(PriorityQueue *pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < pq->size && pq->data[leftChild] > pq->data[largest]) {
        largest = leftChild;
    }
    if (rightChild < pq->size && pq->data[rightChild] > pq->data[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        // Swap the current element with the largest child
        int temp = pq->data[index];
        pq->data[index] = pq->data[largest];
        pq->data[largest] = temp;

        heapifyDown(pq, largest);
    }
}

// Main function to demonstrate the priority queue
int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);

    insert(&pq, 10);
    insert(&pq, 20);
    insert(&pq, 15);
    insert(&pq, 30);

    printf("Max element: %d\n", getMax(&pq));
    printf("Extracted max: %d\n", extractMax(&pq));
    printf("Max element after extraction: %d\n", getMax(&pq));

    return 0;
}
