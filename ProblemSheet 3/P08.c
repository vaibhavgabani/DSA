/*
 * P08.c
 *
 *  Created on: 14-Oct-2024
 *      Author: root
 */

#include<stdio.h>
#include<stdlib.h>
struct node{
	int co;
	int power;
	struct node *next;
}*first = NULL , *last = NULL , *temp = NULL , *curr = NULL;

int empty(){
	if(first == NULL){
		return 1;
	}
	return 0;
}

void insert_last(int pow){
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter Coefficient : ");
	scanf("%d",&temp->co);
	temp->power = pow;
	if(empty()){
		first = last = temp;
	} else {
		last->next = temp;
		last = temp;
	}
	return;
}

void traversal(){
	if(empty()){
		printf("Linked List is empty!!!\n");
		return;
	}
	curr = first;
	while(curr != NULL){
		printf("%dX%d + ",curr->co,curr->power);
		curr = curr->next;
	}
}


int main(){
	int choice;
		while(1){
			printf("\n\nPress 1: Insert power \nPress 2: Traverse\nEnter your choice : ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
			{
				int max;
				printf("Enter Power : ");
				scanf("%d",&max);
				for(int i = max ; i>=0 ; i--){
					insert_last(i);
				}
			}
				break;
			case 2:
				traversal();
				break;
			case 0:
				return 0;
			}
		}
	return -1;
}

