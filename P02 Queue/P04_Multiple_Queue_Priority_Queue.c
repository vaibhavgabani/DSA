#include<stdio.h>
#define max 5
int pQ1[max] , pQ2[max] , pQ3[max];
int f1 = 0 , f2 = 0 , f3 = 0 , r1 = -1 , r2 = -1 , r3 = -1;

void enqueue();
void print();

void deueue();

int main(){
	int choice;
		do{
			// print();
			printf("\n\n\n");
			printf("\n\nPress 1: enqueue\nPress 2: dequeue\nPress 3 : traversal\nPress 0 : Exit\n");
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
			case 0:
				return -1;
			}

		}while(1);
		return 0;
	return 0;
}

void enqueue(){
	int choice = 0, value = 0;
	printf("Press 1 : First Priority\nPress 2 : Second Priority\nPress 3 : Third Priority\n");
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
	case 3:
		if(r3 == max - 1){
			printf("Queue 3 is Full !!!\n");
			break;
		}
		printf("Enter value in Queue 3 : ");
		scanf("%d",&value);
		pQ3[++r3] = value;
	break;
	default:
	printf("Enter valid choice...\n");
	}
	return;
}

void print(){
	printf("Q1:\n");
	for(int i = f1 ; i <= r1 ; i++){
		printf("%d ",pQ1[i]);
	}
	printf("\n");

	printf("Q2:\n");
	for(int i = f2 ; i <= r2 ; i++){
		printf("%d ",pQ2[i]);
	}
	printf("\n");

	printf("Q3:\n");
	for(int i = f3 ; i <= r3 ; i++){
		printf("%d ",pQ3[i]);
	}
	printf("\n");
	return;

}


void deueue(){
	int choice = 0 ;
	printf("Press 1 : dequeue in Queue 1\nPress 2 : dequeue in Queue 2\nPress 3 : dequeue in Queue 3\n");
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
			f1++;
		}
		printf("Dequeue successfully...\n");
	break;
	case 2:
		if(f2 == 0 && r2 == -1){
			printf("Queue 2 is Empty !!!");
			return;
		}
		if((r1 != -1)){
			printf("There is value in Higher Priority Queue so Dequeue is not possible !!!\n");
			return;
		}

		if(f2 == r2){
			f2 = 0 , r2 = -1;
		} else {
			f2++;
		}
		printf("Dequeue successfully...\n");
		break;
	case 3:
		if(f1 == 0 && r1 == -1){
			printf("Queue 1 is Empty !!!");
			return;
		}
		if((r1 != -1) && (r2 != -1)){
			printf("There is value in Higher Priority Queue so Dequeue is not possible !!!\n");
			return;
		}

		if(f3 == r3){
			f3 = 0 , r3 = -1;
		} else {
			f3++;
		}

		printf("Dequeue successfully...\n");
		break;
	default:
		printf("Enter valid choice \n");
		break;
	}
	return;
}
