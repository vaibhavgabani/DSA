/*
 * P12.c
 *
 *  Created on: 29-Jul-2024
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack_arr[MAX];
int *top;

void push();
void traverse_b_to_t();
void traverse_t_to_b();
void pop();
void peep();

int main(){
    int choice;
    // Allocate memory for top and initialize it
    top = (int*)malloc(sizeof(int));
    if (top == NULL) {
        printf("Memory allocation failed\n");
        return 1;  // Return an error code
    }
    *top = -1;  // Initialize top to -1 indicating an empty stack

    do {
        printf("Enter 1 : for push\nEnter 2 : for pop\nEnter 3 : for peep\nEnter 4 : traverse Bottom to top\nEnter 5 : traverse top to Bottom\nEnter 0 : Exit");
        printf("\nEnter your choice here \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n\n");
                push();
                break;
            case 2:
                printf("\n\n");
                pop();
                break;
            case 3:
                printf("\n\n");
                peep();
                break;
            case 4:
                printf("\n\n");
                traverse_b_to_t();
                break;
            case 5:
                printf("\n\n");
                traverse_t_to_b();
                break;
            case 0:
                free(top);  // Free the allocated memory for top
                return 0;   // Return 0 to indicate successful exit
            default:
                printf("\n\n");
                printf("Enter a valid choice\n");
                break;
        }
    } while (1);

    return 0;
}

void push() {
    if (*top == MAX - 1) {
        printf("Stack is Full!!!!\n");
        return;
    }
    (*top)++;
    printf("Enter value which you want to add : ");
    scanf("%d", &stack_arr[*top]);
    printf("Value added successfully.....\n");
}

void traverse_b_to_t() {
    if (*top == -1) {
        printf("Stack is empty!!!!\n");
        return;
    }
    for (int i = 0; i <= *top; i++) {
        printf("| %d |\n", stack_arr[i]);
    }
    printf("-----\n");
}

void traverse_t_to_b() {
    if (*top == -1) {
        printf("Stack is empty!!!!\n");
        return;
    }
    for (int i = *top; i >= 0; i--) {
        printf("| %d |\n", stack_arr[i]);
    }
    printf("-----\n");
}

void pop() {
    if (*top == -1) {
        printf("Stack is empty!!!!\n");
        return;
    }
    printf("Popped value: %d\n", stack_arr[*top]);
    (*top)--;
}

void peep() {
    if (*top == -1) {
        printf("Stack is empty!!!\n");
        return;
    }
    printf("| %d |<- TOP \n", stack_arr[*top]);
}
