/*
 * P03.c
 *
 *  Created on: 02-Sep-2024
 *      Author: root
 */


#include<stdio.h>
#define max 4
int queue[max];
int r = -1 , f = 0;

void push();
void traverse();
void pop();
void peep();

int main(){
	int choice;
	do{
		printf("Enter 1 : for push\nEnter 2 : for pop\nEnter 3 : for peep\nEnter 4 : traverse\nEnter 5 : Exit");
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
	if(r == max - 1){
		printf("Queue is Full!!!!\n");
		return;
	}
	r++;
	printf("Enter value which you want to add : ");
	scanf("%d",&queue[r]);
	printf("value added successfully.....\n");
	return;
}

void traverse(){
	if(r == -1){
		printf("Queue is empty!!!!\n");
		return;
	}
	for(int i = r ; i >= 0 ; i--){
		printf("| %d |\n",queue[i]);
	}
	printf("------\n");
}

void pop(){
	if(r == max - 1){
		printf("Queue is empty!!!!\n");
		return;
	}
	queue[r] = 0;
	r--;
	return;
}

void peep(){
	if(r == -1){
		printf("Queue is empty!!!\n");
		return;
	}
	printf("| %d |<- r \n",queue[r]);
}
