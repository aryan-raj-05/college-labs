#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

typedef struct node {
    char usn[SIZE], name[SIZE], branch[SIZE];
    int sem;
    long int phone;
    struct node *next;
} node;

node *head = NULL;
int size = 0;

node *getNode();
void display();
void addFirst();
void deleteFirst();
void addLast();
void deleteLast();
void stackDemo();

int main() {
    int ch;

    while (1) {
        printf("\n---Menu---\n");
        printf("1. Create SLL\n");
        printf("2. Display\n");
        printf("3. Insert At End\n");
        printf("4. Delete At End\n");
        printf("5. Stack Demo\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                int initSize;
                printf("Enter Number of Students: ");
                scanf("%d", &initSize);
                for (int i = 0; i < initSize; i++)  addFirst();
                break;
            case 2: display();      break;
            case 3: addLast();      break;
            case 4: deleteLast();   break;
            case 5: stackDemo();    break;
            case 6: exit(0);
            default:
                printf("Invalid Choice. Enter Again\n");
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int count = 0;
    node *iter = head;
    while (iter != NULL) {
        printf("%d || USN: %s | Name: %s | Branch: %s | Sem: %d | Phone: %ld\n",
            ++count, iter->usn, iter->name, iter->branch, iter->sem, iter->phone);
        iter = iter->next;
    }
}

void addFirst() {
    node *toAdd = getNode();
    if (head == NULL) {
        head = toAdd;
        return;
    }
    toAdd->next = head;
    head = toAdd;
    size++;
}

void deleteFirst() {
    printf("The student with usn: %s is deleted", head->usn);
    node *tmp = head;
    head = head->next;
    free(tmp);
    size--;
}

void addLast() {
    node *toAdd = getNode();
    node *iter = head;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = toAdd;
    size++;
}

void deleteLast() {
    if (head->next == NULL) {
        printf("The student with usn: %s is deleted\n", head->usn);
        free(head);
        head = NULL;
        return;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    printf("The student with usn: %s is deleted\n", fast->usn);
    slow->next = NULL;
    free(fast);
    size--;
}

void stackDemo() {
    int choice;

    while (1) {
        printf("\n---Stack Demo---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addFirst();     break;
            case 2: deleteFirst();  break;
            case 3: display();      break;
            case 4: return;
            default:
                printf("Invalid Choice. Enter Again\n");
        }
    }
}

node *getNode() {
    node *tmp = (node *) malloc(sizeof(node));
    printf("Enter Name, USN, Branch, Sem and Phone No.: ");
    scanf("%s %s %s %d %ld", tmp->name, tmp->usn, tmp->branch, &tmp->sem, &tmp->phone);
    tmp->next = NULL;
    return tmp;
}