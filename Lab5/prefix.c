#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 100

int top = -1;
char infix[size];
char prefix[size];
char stack[size];

int IsOperator(char);
int precedence(char);
void convert(char[], char[]);
void push(char);
char pop();

void push(char op)
{
    if (top == size - 1)
        printf("Stack overflow");
    else
        stack[++top] = op;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow");
        return '\0';
    }
    else
        return stack[top--];
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

void reverseString(char str[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void convert(char infix[], char prefix[])
{
    int i, j = 0;
    char ch, op;

    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;
        else if (isalnum(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == ')')
        {
            push(ch);
        }
        else if (ch == '(')
        {
            while ((op = pop()) != ')')
            {
                prefix[j++] = op;
            }
        }
        else if (IsOperator(ch))
        {
            while (top != -1 && precedence(stack[top]) > precedence(ch))
            {
                op = pop();
                prefix[j++] = op;
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        op = pop();
        prefix[j++] = op;
    }

    prefix[j] = '\0';
    reverseString(prefix);
}

int main()
{
    char input[100];
    printf("Enter infix expression: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // Removing the newline character from input

    convert(input, prefix);
    printf("Infix: %s\n", input);
    printf("Prefix: %s\n", prefix);

    return 0;
}

