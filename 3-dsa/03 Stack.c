#include <stdio.h>

#define SIZE 3

int stack[SIZE];
int top = -1;

void push(int val);
int pop();
void display();
void checkPalindrome();
int isFull();
int isEmpty();

int main() {
    int ch;

    while (1) {
        printf("---Menu---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                int val;
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                int popedVal = pop();
                if (popedVal == -1) 
                    printf("Stack Empty\n");
                else
                    printf("The deleted element is: %d\n", popedVal);
                break;
            case 3: checkPalindrome();      break;
            case 4: display();              break;
            case 5: return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}

void push(int val) {
    if (isFull()) {
        printf("Stack OverFlow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top--];
}

void display() {
    printf("Stack Contents are: ");
    for (int i = 0; i <= top; i++) {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

void checkPalindrome() {
    display();

    printf("Stack Contents in reverse are: ");
    for (int i = top; i > -1; i--) {
        printf("%d", stack[i]);
    }
    printf("\n");

    int i = 0, j = top;
    while (i < j) {
        if (stack[i] != stack[j]) {
            printf("Stack contents do not form palindrom\n");
            return;
        }
        i++;
        j--;
    }

    printf("Stack contents form a palidrome\n");
}

int isFull() {
    return top == (SIZE - 1);
}

int isEmpty() {
    return top == -1;
}