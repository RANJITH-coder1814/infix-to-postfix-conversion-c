#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push operation */
void push(char ch) {
    stack[++top] = ch;
}

/* Pop operation */
char pop() {
    return stack[top--];
}

/* Operator priority */
int priority(char ch) {
    if (ch == '(' || ch == '#') return 1;
    if (ch == '+' || ch == '-') return 2;
    if (ch == '*' || ch == '/' || ch == '%') return 3;
    if (ch == '^') return 4;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter valid INFIX expression: ");
    fgets(infix, MAX, stdin);

    push('#');

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } 
        else if (infix[i] == '(') {
            push('(');
        } 
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        } 
        else {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while (stack[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("\nINFIX EXPRESSION  : %s", infix);
    printf("POSTFIX EXPRESSION: %s\n", postfix);

    return 0;
}
