#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPRESSION_SIZE 100
struct Stack {
    char data[MAX_EXPRESSION_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char value) {
    if (stack->top >= MAX_EXPRESSION_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}
int precedence(char operator) {
    if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '+' || operator == '-') {
        return 1;
    }
    return 0;
}
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void infixToPrefix(char* infixExpression, char* prefixExpression) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    reverseString(infixExpression);

    for (int i = 0; infixExpression[i] != '\0'; i++) {
        char symbol = infixExpression[i];
        if (symbol == '(') {
            while (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] != ')') {
                prefixExpression[strlen(prefixExpression)] = pop(&operatorStack);
            }
            pop(&operatorStack);
        } else if (symbol == ')') {
            push(&operatorStack, symbol);
        } else if (symbol >= '0' && symbol <= '9') {
            prefixExpression[strlen(prefixExpression)] = symbol;
        } else {
            while (!isEmpty(&operatorStack) && precedence(operatorStack.data[operatorStack.top]) >= precedence(symbol)) {
                prefixExpression[strlen(prefixExpression)] = pop(&operatorStack);
            }
            push(&operatorStack, symbol);
        }
    }

    while (!isEmpty(&operatorStack)) {
        prefixExpression[strlen(prefixExpression)] = pop(&operatorStack);
    }

    reverseString(prefixExpression);
}

int main() {
    char infixExpression[MAX_EXPRESSION_SIZE];
    char prefixExpression[MAX_EXPRESSION_SIZE];

    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strlen(infixExpression) - 1] = '\0';

    infixToPrefix(infixExpression, prefixExpression);

    printf("Equivalent prefix expression: %s\n", prefixExpression);

    return 0;
}

