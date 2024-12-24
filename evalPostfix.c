#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 256

int eval(char *expr);
int isDigit(char c);
void push(int val);
int pop();

int stack[SIZE];
int top = -1;

int main() {
    char expr[64];
    printf("Enter valid postfix expression: ");
    scanf("%s", expr);

    int res = eval(expr);
    printf("Result: %d\n", res);
}

int eval(char *expr) {
    int i = 0;
    while (expr[i] != '\0') {
        if (isDigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (expr[i]) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
                case '^':
                    push((int) pow(a, b));
                    break;
                default:
                    printf("Invalid Operation given\n");
                    exit(1);
                    break;
            }
        }
        i++;
    }

    if (top == 0)
        return pop();
    else {
        printf("Invalid Expression Given\n");
        return -1;
    }
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void push(int val) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}