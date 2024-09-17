/*
 * P04.cpp
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
void dequeue_f(){
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
void dequeue_r(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	} else if( r == f){
		f = 0;
		r = -1;
		return;
	} else {
		r--;
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
		printf("R = %d & F = %d\n\n",f,r);
		printf("\n\nPress 1: enqueue\nPress 2: dequeue_f\nPress 3 : dequeue_r\nPress 4 : traversal\nPress 5 : Rear Element\nPress 6 : Front Element\nPress 0 : Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			enqueue();
			break;
		case 2:
			dequeue_f();
			break;
		case 3:
			dequeue_r();
			break;
		case 4:
			traversal();
			break;
		case 5:
			rear();
			break;
		case 6:
			front();
			break;
		case 0:
			return -1;
		}

	}while(1);
	return 0;
}

