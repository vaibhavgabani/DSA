/*
 * P09.c
 *
 *  Created on: 08-Oct-2024
 *      Author: root
 */


#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*first = NULL , *last = NULL , *temp = NULL , *curr = NULL;

int empty(){
	if(first == NULL){
		return 1;
	}
	return 0;
}

void insert_first(){
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter Value : ");
	scanf("%d",&temp->data);

	if(empty()){
		first = last = temp;
	} else {
		temp->next = first;
		first = temp;
	}
	return;
}

void insert_last(){
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter Value : ");
	scanf("%d",&temp->data);

	if(empty()){
		first = last = temp;
	} else {
		last->next = temp;
		last = temp;
	}
	return;
}


void insert_bt(){
	if(empty()){
		printf("there is no node\n\n");
		return;
	}
	int index , cnt = 1;
	printf("Enter index : ");
	scanf("%d",&index);
	curr = first;

	while(curr->next != NULL &&  index > cnt){
		curr = curr->next;
		cnt++;
	}
	if(cnt == index){
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter Value : ");
		scanf("%d",&temp->data);

		temp->next = curr->next;
		curr->next = temp;
		if(curr == last){
			last = temp;
		}
		printf("Element added\n");
	} else {
		printf("Enter valid index!!!\n");
	}


	return;
}

void delete_first(){
	if(empty()){
		printf("there is no node\n\n");
		return;
	}
	temp = first;
	printf("%d element deleted\n",temp->data);
	if(first == last){
		first = last = NULL;
	} else {
		first = first->next;
	}
	free(temp);

}

void delete_last(){
	if(empty()){
		printf("there is no node\n\n");
		return;
	}
	temp = last;
	printf("%d element deleted\n",temp->data);
	if(first == last){
		first = last = NULL;
	} else {
		curr = first;
		while(curr->next != last){
			curr = curr->next;
		}
		curr->next = NULL;
		last = curr;
		free(temp);
	}
}

void traversal(){

	printf("\ntemp = %d\n",temp->data);
	curr = first;
	while(curr != NULL){
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

void sort_a(){
	for(struct node *i = first ; i != NULL ; i = i->next){
		for(struct node *j = first ; j != NULL ; j = j->next){
			if(i->data <= j->data){
				int tmp = j->data;
				j->data = i->data;
				i->data = tmp;
			}
		}
	}
}

void sort_b(){
	for(struct node *i = first ; i != NULL ; i = i->next){
		for(struct node *j = first ; j != NULL ; j = j->next){
			if(i->data >= j->data){
				int tmp = j->data;
				j->data = i->data;
				i->data = tmp;
			}
		}
	}
}

void sum(){
	int sum = 0;
	for(struct node *i = first ; i != NULL ; i = i->next){
		sum += i->data;
	}
	printf("sum of all node is : %d",sum);
}
int main(){
	int choice;
		while(1){
			printf("\n\nPress 1: Insert_first\nPress 2: Insert Last\nPress 3: Insert between\nPress 4: Traverse\nPress 5: Delete first\nPress 6: Delete Last\nPress 7: sort in Accending\nPress 8: sort in Decending\nPress 9: SUM of Allnode\nPress 0: Exit\n\nEnter your choice : ");
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
				traversal();
				break;
			case 5:
				delete_first();
				break;
			case 6:
				delete_last();
				break;
			case 7:
				sort_a();
				break;
			case 8:
				sort_b();
				break;
			case 9:
				sum();
				break;
			case 0:
				return 0;
			}
		}
	return -1;
}

