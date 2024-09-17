/*
 * P02.c
 *
 *  Created on: 06-Sep-2024
 *      Author: root
 */


#include<stdio.h>
#define max 6
int cQ[max];
int r = -1 , f = -1;


void enqueue(int);
void dequeue();
void traversal();
void front();
void rear();

int main(){
	int choice , v = 0;
	do{
//		print();
		printf("\n\nPress 1: enqueue\nPress 2: dequeue\nPress 3 : traversal\nPress 4 : Rear Element\nPress 5 : Front Element\nPress 0 : Exit\n");
		printf("Enter here : \n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter value : ");
			scanf("%d",&v);
			enqueue(v);
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
void enqueue(int value){
	if((r == max -1 && f == 0) || (r < f - 1)){
		printf("stack is full");
	} else if (r == -1 && f == -1){
		r = 0 , f = 0;
	} else if (r == max -1 && f > 0){
		r = 0;
	} else {
		r++;
	}
	cQ[r] = value;
	return;
}

void dequeue(){
	if(f == -1 && r == -1){
		printf("Queue is empty...");
	} else if(r == f){
		r = -1 , f = -1;
		printf("Dequeue Successfully...\n");
	} else if (f < r){
		f++;
		printf("Dequeue Successfully...\n");
	}
	if(f == max - 1 && r > 0){
		f = 0;
	}
}

void traversal(){
	if(r < f){
		for(int i = f ; i <= max - 1 ; i++){
			printf("%d\t",cQ[i]);
		}
		for(int i = 0 ; i <= r ; i++){
			printf("%d\t",cQ[i]);
		}
	} else {
		for(int i = f ; i<= r ; i++){
			printf("%d\t",cQ[i]);
		}
	}
}


void front(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	printf("Front Element is : %d",cQ[f]);
	return;
}

void rear(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	printf("Rear Element is : %d",cQ[r]);
	return;
}
