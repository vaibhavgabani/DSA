/*
 * P08.c
 *
 *  Created on: 06-Sep-2024
 *      Author: root
 */

#include<stdio.h>
#define max 5
struct Priority_Queue{
	int data;
	int pri;
}pQ[max],temp;

int f = 0 , r = -1;
void enqueue();
void prio();
void dequeue();
void travers();
void front();
void rear();

int main(){
	int choice;
	while(1){
		printf("\n\nPress 1: enqueue\nPress 2: dequeue\nPress 3 : traversal\nPress 4 : Rear Element\nPress 5 : Front Element\nPress 0 : Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			enqueue();
			prio();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			travers();
			break;
		case 4:
			rear();
			break;
		case 5:
			front();
			break;
		case 0:
			return 0;
		default:
			printf("Enter Valid Choice !!!\n");
			break;
		}
	}
	return -1;
}

void enqueue(){
	if(f == 0 && r == max - 1){
		printf("Queue is full!!!\n");
		return;
	}
	r++;
	printf("Enter Value : ");
	scanf("%d",&pQ[r].data);
	printf("Enter Priority : ");
	scanf("%d",&pQ[r].pri);

	return;
}

void prio(){
	for(int i = f ; i  <= r ; i++) {
		for(int j = f ; j <= r ; j++) {
			if(pQ[i].pri < pQ[j].pri){
				temp = pQ[j];
				pQ[j] = pQ[i];
				pQ[i] = temp;
			}
		}
	}
	return;
}

void dequeue(){
	if(f == 0 && r == -1){
		printf("Queue is empty !!!\n");
		return;
	}
	if (f == r){
		f = 0 , r = -1;
	} else {
		f++;
	}
	return;
}

void travers(){
	if(f == 0 && r == -1){
		printf("Queue is empty !!!\n");
		return;
	}
	for(int i = f ; i <= r ; i++){
		printf("%d (%d) | ",pQ[i].data,pQ[i].pri);
	}
}


void front(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	printf("Front Element is : %d",pQ[f]);
	return;
}

void rear(){
	if(r == -1 && f == 0){
		printf("Queue is empty...\n");
		return;
	}
	printf("Rear Element is : %d",pQ[r]);
	return;
}
