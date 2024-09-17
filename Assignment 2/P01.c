/*
 * P01.c
 *
 *  Created on: 02-Sep-2024
 *      Author: root
 */

#include<stdio.h>
#define max 5
int queue[max];
int r = -1 , f = 0;

void enqueue(){
	if(r == max -1){
		printf("queue is full..");
		return;
	}
	printf("Enter Value : ");
	scanf("%d",&queue[++r]);
	return;
}
void dequeue(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	} else if( r == f){
		f = 0;
		r = -1;
		return;
	} else {
		f++;
		printf("Dequeue successfully....\n\n");
	}
	return;
}
void traversal(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	for(int i = f ; i <= r; i++ ){
		printf("%d\t",queue[i]);
	}
}

void front(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	printf("Front Element is : %d",queue[f]);
	return;
}

void rear(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	printf("Rear Element is : %d",queue[r]);
	return;
}

int main(){
	int choice;
	do{
		printf("\n\nPress 1: enqueue\nPress 2: dequeue\nPress 3 : traversal\nPress 4 : Rear Element\nPress 5 : Front Element\nPress 0 : Exit\n");
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
			rear();
			break;
		case 5:
			front();
			break;
		case 0:
			return -1;
		}

	}while(1);
	return 0;
}
