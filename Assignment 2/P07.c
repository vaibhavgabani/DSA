/*
 * P07.c
 *
 *  Created on: 02-Sep-2024
 *      Author: root
 */
/*
 * P14_Priority_Queue.c
 *
 *  Created on: 20-Aug-2024
 *      Author: root
 */
#include<stdio.h>
#define max 5
int pQ1[max] , pQ2[max];
int f1 = 0 , f2 = 0 , r1 = -1 , r2 = -1 ;

void enqueue();
void print();
void deueue();
void rear();
void front();

int main(){
	int choice;
		do{
			printf("\n");
			printf("\n\nPress 1: enqueue\nPress 2: dequeue\nPress 3: traversal\nPress 4: Rear Element\nPress 5: Front Element\nPress 0: Exit\n\nEnter your choice : ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				deueue();
				break;
			case 3:
				print();
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
	return 0;
}

void enqueue(){
	int choice = 0, value = 0;
	printf("Press 1 : First Priority\nPress 2 : Second Priority\n");
	printf("Enter Choice : ");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		if(r1 == max - 1){
			printf("Queue 1 is Full !!!\n");
			break;
		}
		printf("Enter value in Queue 1 : ");
		scanf("%d",&value);
		pQ1[++r1] = value;
	break;
	case 2:
		if(r2 == max - 1){
			printf("Queue 2 is Full !!!\n");
			break;
		}
		printf("Enter value in Queue 2 : ");
		scanf("%d",&value);
		pQ2[++r2] = value;
	break;
	default:
	printf("Enter valid choice...\n");
	}
	return;
}

void deueue(){
	int choice = 0 ;
	printf("Press 1 : dequeue in Queue 1\nPress 2 : dequeue in Queue 2\n");
	printf("Enter Choice : ");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		if(f1 == 0 && r1 == -1){
			printf("Queue 1 is Empty !!!");
			return;
		}
		if(f1 == r1){
			f1 = 0 , r1 = -1;
		} else {
			pQ1[f1++] = 0;
		}
		printf("Dequeue successfully...\n");
	break;
	case 2:
		if(f2 == 0 && r2 == -1){
			printf("Queue 2 is Empty !!!");
			return;
		}
		if((r1 != -1)){
			printf("There is value in Higher Priority Queue so Dequeue is not possible !!!");
			return;
		}

		if(f2 == r2){
			f2 = 0 , r2 = -1;
		} else {
			pQ1[f2++] = 0;
		}
		printf("Dequeue successfully...\n");
		break;

	default:
		printf("Enter valid choice \n");
		break;
	}
	return;
}

void print(){
	printf("Q1:\n");
	for(int i = 0 ; i <= max - 1 ; i++){
		printf("%d ",pQ1[i]);
	}
	printf("\n");

	printf("Q2:\n");
	for(int i = 0 ; i <= max - 1 ; i++){
		printf("%d ",pQ2[i]);
	}
	printf("\n");
	return;

}
void rear(){
	if(r1 == -1 && f1 == 0){
		printf("\nq1 is empty\n");
	} else {
		printf("\nrear element in Q1 : %d ",pQ1[r1]);
	}
	if(r2 == -1 && f2 == 0){
		printf("\nq2 is empty\n");
	} else {
		printf("\nrear element in Q2 : %d ",pQ2[r2]);
	}
}

void front(){
	if(r1 == -1 && f1 == 0){
		printf("\nq1 is empty\n");
	} else {
		printf("\nFront element in Q1 : %d ",pQ1[f1]);
	}
	if(r2 == -1 && f2 == 0){
		printf("\nq2 is empty\n");
	} else {
		printf("\nFront element in Q2 : %d ",pQ2[f2]);
	}
}
