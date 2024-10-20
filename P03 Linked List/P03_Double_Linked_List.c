/*
 * P17_double_Linked_list.c
 *
 *  Created on: 12-Sep-2024
 *      Author: root
 */
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
}*first = NULL , *last = NULL , *temp = NULL , *curr = NULL;

int is_empty(){
	return first == NULL;
}

void insert_first(){
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter Value  : ");
	scanf("%d",&temp->data);

//	temp->left = NULL;
	if(is_empty()){
		first = last = temp;
	} else {
		temp->right = first;
		first->left = temp;
		first = temp;
	}
}


void insert_last(){
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter Value  : ");
	scanf("%d",&temp->data);
	if(is_empty()){
			first = last = temp;
		} else {
			temp->left = last;
			last->right = temp;
			last = temp;
		}
}

void delete_first(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
	temp = first;
	if(first == last){
		first = last = NULL;
	} else {
		temp->right = NULL;
		first = first->right;
	}
	free(temp);
}

void traversal(){

	printf("\ntemp = %d\n",temp->data);
	curr = first;
	while(curr != NULL){
		printf("%d ",curr->data);
		curr = curr->right;
	}
}


int main(){
	int choice;
		while(1){
			printf("\n\nPress 1: Insert_first\nPress 2: Insert Last\nPress 3: Insert between\nPress 4: Traverse\nPress 5: Delete first\nPress 6: Delete Last\nPress 7: Delete Between\nPress 0: Exit\n\nEnter your choice : ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				insert_first();
				break;
			case 2:
				insert_last();
				break;
//			case 3:
//				insert_bt();
//				break;
			case 4:
				traversal();
				break;
			case 5:
				delete_first();
				break;
//			case 6:
//				delete_last();
//				break;
//			case 7:
//				delete_bt();
//				break;
			case 0:
				return 0;
			}
		}
	return -1;
}
