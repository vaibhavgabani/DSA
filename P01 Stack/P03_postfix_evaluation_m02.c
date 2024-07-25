#include<stdio.h>
#define max 20

// Stack to hold the operands
int stack_arr[max];
int top = -1;

// Function prototypes
void push();
int is_operator(char ch);
void postfix_evaluation();

int main() {
    postfix_evaluation();
    return 0;
}

// Push function to add operand to the stack
void push() {
    if(top == max - 1) {
        printf("Stack is Full!!!!\n");
        return;
    }
    top++;
    scanf("%d", &stack_arr[top]);
    return;
}

// Function to check if the character is an operator
int is_operator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
        return 1;
    }
    return 0;
}

// Function to evaluate the postfix expression
void postfix_evaluation() {
    char str[50];
    printf("\nEnter your Postfix string: ");
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++) {
        // Check if the character is an operator
        if((is_operator(str[i])) == 1) {
            // Ensure there are enough operands for the operation
            if(i < 2) {
                printf("\n%c operation can't be done at %d", str[i], i);
                printf("\n=================================");
                return;
            } else {
                int num1 = 0, num2 = 0, ans = 0;
                // Pop the top two operands from the stack
                num2 = stack_arr[top];
                top--;
                num1 = stack_arr[top];
                // Perform the operation using switch case
                switch (str[i]) {
                    case '+':
                        ans = num1 + num2;
                        break;
                    case '-':
                        ans = num1 - num2;
                        break;
                    case '*':
                        ans = num1 * num2;
                        break;
                    case '/':
                        ans = num1 / num2;
                        break;
                }
                // Push the result back to the stack
                stack_arr[top] = ans;
            }
        } else {
            // If the character is an operand, prompt the user for its value
            printf("\nEnter value of %c = ", str[i]);
            push();
        }
    }
    // Output the final result
    printf("\nFinal output = %d", stack_arr[top]);
    top--;
    return;
}
