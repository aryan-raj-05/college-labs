#include <stdio.h>

int size;

int hash(int key);
int rehash(int key);

int main() {
    printf("Enter size of Hash Table: ");
    scanf("%d", &size);

    int hashTable[size];
    for (int i = 0; i < size; i++) {
        hashTable[i] = -1;
    }

    int numElements;
    printf("Enter the number of Elements: ");
    scanf("%d", &numElements);

    int val;
    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);

        int index = hash(val);
        while (hashTable[index] != -1) {
            index = rehash(index);
        }
        hashTable[index] = val;
    }

    printf("Elements of array: \n");
    for (int i = 0; i < size; i++) {
        printf("Element at Position: %d = %d\n", i, hashTable[i]);
    }

    return 0;
}

int hash(int key) {
    return key % size;
}

int rehash(int key) {
    return (key + 1) % size;
}