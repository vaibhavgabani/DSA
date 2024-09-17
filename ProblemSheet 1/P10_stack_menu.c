/*
 * P10.c
 *
 *  Created on: 25-Jul-2024
 *      Author: root
 */

#include<stdio.h>
#define max 4
int stack_arr[max];
int top = -1;

int main(){
	int choice;
	do{
		printf("Enter 1 : for push\nEnter 2 : for pop\nEnter 3 : for peep\nEnter 4 : traverse Bottom to top\nEnter 5 : traverse top to Bottom\nEnter 0 : Exit");
		printf("\nEnter your choice here \n");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				printf("\n\n");
				if(top == max - 1){
						printf("Stack is Full!!!!\n");
						break;
					}
					top++;
					printf("Enter value which you want to add : ");
					scanf("%d",&stack_arr[top]);
					printf("value added successfully.....\n");
				break;
			case 2:
				printf("\n\n");
				if(top == max - 1){
						printf("Stack is empty!!!!\n");
						break;
					}
					stack_arr[top] = 0;
					top--;
				break;
			case 3:
				printf("\n\n");
				if(top == -1){
						printf("stack is empty!!!\n");
						break;
					}
					printf("| %d |<- TOP \n",stack_arr[top]);
				break;
			case 4:
				printf("\n\n");
				if(top == -1){
						printf("Stack is empty!!!!\n");
						break;
					}
					for(int i = top ; i >= 0 ; i--){
						printf("| %d |\n",stack_arr[i]);
					}
					printf("-----\n");
				break;
			case 5:
				printf("\n\n");
				if(top == -1){
						printf("Stack is empty!!!!\n");
						break;
					}
					for(int i = 0 ; i <= top ; i++){
						printf("| %d |\n",stack_arr[i]);
					}

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




