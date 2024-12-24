#include <stdio.h>

#define LEN 128

char stack[LEN];
int top = -1;

void convertToPostfix(char *infix, char *postfix);
int prec(char op);
void push(char c);
char pop();
int isAlNum(char c);

int main() {
    char infx[LEN], postfx[LEN];
    printf("Enter infix expression: ");
    fgets(infx, LEN, stdin);

    convertToPostfix(infx, postfx);
    printf("Corresponding Postfix Expression is: %s\n", postfx);
}

void convertToPostfix(char *infix, char *postfix) {
    int postIter = 0;
    for (int iter = 0; infix[iter] != '\0'; iter++) {
        if (isAlNum(infix[iter])) {
            postfix[postIter++] = infix[iter];
        } else {
            switch(infix[iter]) {
                case '(': 
                    push(infix[iter]);    
                    break;
                case ')':
                    while (stack[top] != '(')
                        postfix[postIter++] = pop();
                    pop();
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                case '%':
                    while (prec(stack[top]) > prec(infix[iter]))
                        postfix[postIter++] = pop();
                    push(infix[iter]);
            }
        }
    }

    while (top > -1) {
        postfix[postIter++] = pop();
    }
    postfix[postIter] = '\0';
}

int prec(char op) {
    if      (op == '+' || op == '-')    return 1;
    else if (op == '*' || op == '/')    return 2;
    else if (op == '%')                 return 3;
    else if (op == '^')                 return 4;
    else                                return 0;
}

void push(char c) {
    if (top == LEN - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int isAlNum(char c) {
    return  (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
}