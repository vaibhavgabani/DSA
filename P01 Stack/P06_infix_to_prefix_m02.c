#include<stdio.h>
#include<string.h>
# define MAX 100
char infix[MAX] , stack[MAX] , prefix[MAX];
int top = -1;
int priority(char);
void xstrrev(char *ptr);

void infix_to_prefix() {
    printf("Enter Infix: ");
    scanf("%s", infix);
    strrev(infix);
    
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {  // Changed from isalpha to is_alpha
            prefix[k++] = infix[i];
        } else if (infix[i] == ')') {
            if (top < MAX - 1) {
                stack[++top] = infix[i]; // Directly push to stack
            }
        } else if (infix[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[k++] = stack[top--]; // Directly pop from stack
            }
            if (top != -1) {
                top--; // Remove the ')' from stack
            }
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (top != -1 && priority(stack[top]) > priority(infix[i])) {
                prefix[k++] = stack[top--]; // Directly pop from stack
            }
            if (top < MAX - 1) {
                stack[++top] = infix[i]; // Directly push to stack
            }
        }
    }

    while (top != -1) {
        prefix[k++] = stack[top--]; // Directly pop from stack
    }
    prefix[k] = '\0';
    xstrrev(prefix);
    printf("Prefix: %s\n", prefix);
}

int main(){
    infix_to_prefix();
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

void xstrrev(char *ptr){
	int l;
    char *start, *end;
    start = ptr;
    end = ptr + strlen(ptr) - 1;
    while (start < end) {
        char temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
	return;
}