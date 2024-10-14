/*
 * P03.c
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

void enqueue(){
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

void dequeue(){
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

void traversal(){

//	printf("\ntemp = %d\n",temp->data);
	curr = first;
	while(curr != NULL){
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

void disp_f(){
	if(empty()){
		printf("there is no node\n\n");
		return;
	}
	printf("| %d |",first->data);
}
void disp_r(){
	if(empty()){
		printf("there is no node\n\n");
		return;
	}
	printf("| %d |",last->data);
}

int main(){
	int choice;
		while(1){
			printf("\n\nPress 1 :Enqueue\nPress 2: Dequeue\nPress 3: Traversal\nPress 4: display Frount\nPress 5:Display Rear\nPress 0: Exit\n\nEnter your choice : ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				traversal();
				break;
			case 4:
				disp_f();
				break;
			case 5:
				disp_r();
				break;
			case 0:
				return 0;
			}
		}
	return -1;
}

