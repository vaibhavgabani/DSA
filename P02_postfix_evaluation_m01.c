/*
 * P07_postfix_evaluation.c
 *
 *  Created on: 19-Jul-2024
 *      Author: root
 */

#include<stdio.h>
#define max 4
int stack_arr[max];
int top = -1;

void push();
void traverse();
void pop();
void peep();
void div();
void mul();
void sub();
void sum();
int main(){
	int choice;
	do{
		printf("Enter 1 : for push\nEnter 2 : for pop\nEnter 3 : for peep\nEnter 4 : traverse\nEnter 5 : '+'\nEnter 6 : '-'\nEnter 7 : '*'\nEnter 8 : '/'\nEnter 0 : Exit");
		printf("\nEnter your choice here \n");
			scanf("%d",&choice);
			switch(choice){
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
				traverse();
				break;
			case 5:
				printf("\n\n");
				sum();
				break;
			case 6:
				printf("\n\n");
				sub();
				break;
			case 7:
				printf("\n\n");
				mul();
				break;
			case 8:
				printf("\n\n");
				div();
				break;
			case 0:
				return 1;
			default:
				printf("\n\n");
				printf("enter valid choice\n");
				break;

			}
	}while(1);

	return 0;
}

void push(){
	if(top == max - 1){
		printf("Stack is Full!!!!\n");
		return;
	}
	top++;
	printf("Enter value which you want to add : ");
	scanf("%d",&stack_arr[top]);
	printf("value added successfully.....\n");
	return;
}

void traverse(){
	if(top == -1){
		printf("Stack is empty!!!!\n");
		return;
	}
	for(int i = top ; i >= 0 ; i--){
		printf("| %d |\n",stack_arr[i]);
	}
	printf("-----\n");
}

void pop(){
	if(top == max - 1){
		printf("Stack is empty!!!!\n");
		return;
	}
	stack_arr[top] = 0;
	top--;
	return;
}

void peep(){
	if(top == -1){
		printf("stack is empty!!!\n");
		return;
	}
	printf("| %d |<- TOP \n",stack_arr[top]);
}

void sum(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 + num2;
	stack_arr[top] = ans;
}
void sub(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 - num2;
	stack_arr[top] = ans;
}

void mul(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 * num2;
	stack_arr[top] = ans;
}

void div(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 / num2;
	stack_arr[top] = ans;
}
