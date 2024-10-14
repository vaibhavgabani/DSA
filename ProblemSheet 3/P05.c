/*
 * P05.c
 *
 *  Created on: 04-Oct-2024
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

void insert_bt(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
	int index = 0 , cnt = 1;
	printf("Enter index : ");
	scanf("%d",&index);
	curr = first;
	while(curr->right != NULL && cnt < index){
		curr = curr->right;
		cnt++;
	}
	if(index == cnt){
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter Value  : ");
		scanf("%d",&temp->data);
		temp->right = curr->right;
		curr->right = temp;
		temp->left = curr;
		if(curr == last){
			temp = first;
		} else {
			temp->right->left = temp;
		}
	} else {
		printf("Enter Valid index!!!\n");
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

		first = first->right;
	}
	free(temp);
}

void delete_last(){
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

void traversal_f_to_l(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
//	printf("\ntemp = %d\n",temp->data);
	curr = first;
	while(curr != NULL){
		printf("%d ",curr->data);
		curr = curr->right;
	}
}

void traversal_l_to_f(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
//	printf("\ntemp = %d\n",temp->data);
	curr = last;
	while(curr != NULL){
		printf("%d ",curr->data);
		curr = curr->left;
	}
}


void delete_bt(){
	if(is_empty()){
		printf("linked list is empty!!!\n");
		return;
	}
	temp = first;
	int index = 0 , cnt = 1;
	printf("Enter index : ");
	scanf("%d",&index);
	while(temp->right != NULL && cnt < index){
		temp = temp->right;
		cnt++;
	}
	if(index == cnt){
		if(first == last){
			first = last = NULL;
		} else if(temp == first){
			first = first->right;
			temp->right = NULL;
		} else if(temp == last){
			last = last->left;
			last->right = NULL;
		} else {
			temp->right->left = temp->left;
			temp->left->right = temp->right;
		}
		free(temp);
	} else {
		printf("Enter Valid index!!!\n");
	}
}

void sort_a(){
	for(struct node *i = first ; i != NULL ; i = i->right){
		for(struct node *j = first ; j != NULL ; j = j->right){
			if(i->data <= j->data){
				int tmp = j->data;
				j->data = i->data;
				i->data = tmp;
			}
		}
	}
}

void sort_b(){
	for(struct node *i = first ; i != NULL ; i = i->right){
		for(struct node *j = first ; j != NULL ; j = j->right){
			if(i->data >= j->data){
				int tmp = j->data;
				j->data = i->data;
				i->data = tmp;
			}
		}
	}
}



int main(){
	int choice;
		while(1){
			printf("\n\nPress 1: Insert_first\nPress 2: Insert Last\nPress 3: Insert between\nPress 4: Traverse from first to last\nPress 5: Delete first\nPress 6: Delete Last\nPress 7: Delete Between\nPress 8: Travers last to first\nPress 9: Sort in Accending Order\nPress 10: Sort in Decending Order\nPress 0: Exit\n\nEnter your choice : ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				insert_first();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				insert_bt();
				break;
			case 4:
				traversal_f_to_l();
				break;
			case 5:
				delete_first();
				break;
			case 6:
				delete_last();
				break;
			case 7:
				delete_bt();
				break;
			case 8:
				traversal_l_to_f();
				break;
			case 9:
				sort_a();
				break;
			case 10:
				sort_b();
				break;
			case 0:
				return 0;
			}
		}
	return -1;
}
