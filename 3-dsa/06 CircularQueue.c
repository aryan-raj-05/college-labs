#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int val);
int dequeue();
void display();
int isEmpty();
int isFull();

int main() {
    int choice;

    while (1) {
        printf("\n---Menu---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                int valToEnq;
                printf("Enter val to insert: ");
                scanf("%d", &valToEnq);
                enqueue(valToEnq);
                break;
            case 2:
                int deqVal = dequeue();
                if (deqVal != -1) {
                    printf("Delted element is: %d\n", deqVal);
                }
                break;
            case 3: display();  break;
            default:
                return 0;
        }
    }
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue Full. Can't add\n");
        return;
    }

    if (isEmpty())  front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Empty");
        return -1;
    }

    int retValue = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return retValue;
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    int iter = front;
    do {
        printf("%d  ", queue[iter]);
        iter = (iter + 1) % SIZE;
    } while (iter != (rear + 1) % SIZE);
    printf("\n");
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return ((rear + 1) % SIZE) == front;
}