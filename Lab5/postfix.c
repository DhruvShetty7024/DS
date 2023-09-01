#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 100

int top1 = -1; // Stack for operators
int top2 = -1; // Stack for postfix expression
char infix[size];
char postfix[size];
char stack[size];

int IsOperator(char);
int precedence(char);
void convert(char[], char[]);
void push(char, int);
char pop(int);

void push(char op, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (top1 == size - 1)
            printf("Stack 1 overflow");
        else
            stack[++top1] = op;
    }
    else if (stackNumber == 2)
    {
        if (top2 == size - 1)
            printf("Stack 2 overflow");
        else
            postfix[++top2] = op;
    }
}

char pop(int stackNumber)
{
    if (stackNumber == 1)
    {
        if (top1 == -1)
        {
            printf("Stack 1 underflow");
            return '\0';
        }
        else
            return stack[top1--];
    }
    else if (stackNumber == 2)
    {
        if (top2 == -1)
        {
            printf("Stack 2 underflow");
            return '\0';
        }
        else
            return postfix[top2--];
    }
    return '\0';
}

int IsOperator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

void convert(char infix[], char postfix[])
{
    int i, j = 0;
    char ch, op;

    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;
        else if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch, 1);
        }
        else if (ch == ')')
        {
            while ((op = pop(1)) != '(')
            {
                postfix[j++] = op;
            }
        }
        else if (IsOperator(ch))
        {
            while (top1 != -1 && precedence(stack[top1]) >= precedence(ch))
            {
                op = pop(1);
                postfix[j++] = op;
            }
            push(ch, 1);
        }
    }

    while (top1 != -1)
    {
        op = pop(1);
        postfix[j++] = op;
    }

    postfix[j] = '\0';
}

int main()
{
    char input[100];
    printf("Enter infix expression: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // Removing the newline character from input

    convert(input, postfix);
    printf("Infix: %s\n", input);
    printf("Postfix: %s\n", postfix);

    return 0;
}
