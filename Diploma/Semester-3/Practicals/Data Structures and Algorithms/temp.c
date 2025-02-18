#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
    double items[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, double value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

double pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

double evaluateRPN(char *expression) {
    Stack stack;
    initStack(&stack);

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (!isOperator(token[0])) {
            double num = atof(token);
            push(&stack, num);
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero!\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", token[0]);
                    exit(1);
            }

            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    if (stack.top == 0) {
        return stack.items[stack.top];
    } else {
        printf("Invalid expression!\n");
        exit(1);
    }
}

int main() {
    char expression[100];

    printf("Enter an RPN expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression) - 1] = '\0';

    double result = evaluateRPN(expression);
    printf("Result: %lf\n", result);

    return 0;
}
