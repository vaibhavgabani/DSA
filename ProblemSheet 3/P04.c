/*
 * P04.c
 *
 *  Created on: 08-Oct-2024
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


void push(){
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

void peep(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
	temp = last;
	if(first == last){
		first = last = NULL;
	} else {
		curr = first;
		while(curr->right != last){
			curr = curr->right;
		}
		curr->right = NULL;
		last = curr;
	}
	free(temp);
}


void traversal(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
//	printf("\ntemp = %d\n",temp->data);
	curr = last;
	while(curr != NULL){
		printf("| %d |\n",curr->data);
		curr = curr->left;
	}
}

void disp_top(){
	if(is_empty()){
		printf("there is no node\n\n");
		return;
	}
	printf("| %d |",last->data);
}

int main(){
	int choice;
		while(1){
			printf("\n\nPress 1 :Push\nPress 2: peep\nPress 3: Traversal\nPress 4: display top\nPress 0: Exit\n\nEnter your choice : ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				push();
				break;
			case 2:
				peep();
				break;
			case 3:
				traversal();
				break;
			case 4:
				disp_top();
				break;
			case 0:
				return 0;
			}
		}
	return -1;
}

