#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

node *createNode() {
    node *n = (node *) malloc(sizeof(node));
    
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone of Employee: ");
    scanf("%s %s %s %s", n->ssn, n->name, n->dept, n->designation);
    scanf("%d %ld", &n->sal, &n->phone);

    n->next = NULL;
    n->prev = NULL;
    return n;
}

void dequeDemo() {
    int ch;
    while (1) {
        printf("\nDeque Operations\n");
        printf("1. Insert At End\n");
        printf("2. Delete at End\n");
        printf("3. Insert at Front\n");
        printf("4. Delete at Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:     addLast();      break;
            case 2:     deleteLast();   break;
            case 3:     addFirst();     break;
            case 4:     deleteFirst();  break;
            case 5:     display();      break;
            case 6:     return;
        }
    }
}

void addFirst() {
    node *tmp = createNode();
    if (head == NULL) {
        head = tmp;
        return;
    }
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    node *tmp = head;
    printf("The employee with the ssn: %s is deleted\n", tmp->ssn);
    head = head->next;
    if (head)   head->prev = NULL;
    free(tmp);
}

void addLast() {
    node *tmp = createNode();
    if (head == NULL) {
        head = tmp;
        return;
    }
    node *iter = head;
    while (iter->next != NULL) 
        iter = iter->next;
    iter->next = tmp;
    tmp->prev = iter;
}

void deleteLast() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    if (head->next == NULL) {
        printf("The employee with the ssn: %s is deleted\n", head->ssn);
        free(head);
        head = NULL;
        return;
    }
    
    node *iter = head;
    while (iter->next != NULL)
        iter = iter->next;
    printf("The employee with the ssn: %s is deleted\n", iter->ssn);
    iter->prev->next = NULL;
    free(iter);
}

void display() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    node *iter = head;
    int count = 0;
    while (iter != NULL) {
        printf("Enode: %d | SSN: %s | Name: %s | Dept: %s | Desig: %s |Salary %d | Phone: %ld\n", ++count, iter->ssn, iter->name, iter->dept, iter->designation, iter->sal, iter->phone);
        iter = iter->next;
    }
    printf("\nNo of Employee Nodes is %d\n", count);
}

int main() {
    int ch;
    while (1) {
        printf("\n~~~Menu~~~\n");
        printf("1. Create DLL of Employee Nodes\n");
        printf("2. Display\n");
        printf("3. Insert At End\n");
        printf("4. Delete At End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete at Front\n");
        printf("7. Double ended queue demo using DLL\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                int n;
                printf("Enter No. of Employees: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) addLast();
                break;
            case 2:     display();      break;
            case 3:     addLast();      break;
            case 4:     deleteLast();   break;
            case 5:     addFirst();     break;
            case 6:     deleteFirst();  break;
            case 7:     dequeDemo();    break;
            case 8:     exit(0);
            default:
                printf("\nInvalid Choice. Enter Valid Choice\n");
        }
    }
}
