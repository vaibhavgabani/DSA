#include<stdio.h>
# define MAX 20
char infix[MAX] , stack[MAX] , postfix[MAX];
int top = -1;
int priority(char);

void infix_to_postfix() {
    printf("Enter Infix: ");
    scanf("%s", infix);
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {  // Changed from isalpha to is_alpha
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            if (top < MAX - 1) {
                stack[++top] = infix[i]; // Directly push to stack
            }
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--]; // Directly pop from stack
            }
            if (top != -1) {
                top--; // Remove the '(' from stack
            }
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[k++] = stack[top--]; // Directly pop from stack
            }
            if (top < MAX - 1) {
                stack[++top] = infix[i]; // Directly push to stack
            }
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--]; // Directly pop from stack
    }
    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);
}

int main(){
    infix_to_postfix();
    return 0;
}

int priority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return 0;
    }
}

// Algorithm
// • If operand
//       print
// • If '('
//       push to stack
// • If ')'
//       pop from stack and print until '(' is found
// • If operator
//       pop from stack and print until an operator with less precedence is found
