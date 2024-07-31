/*
 * P06.c
 *
 *  Created on: 26-Jul-2024
 *      Author: root
 */
#include<stdio.h>
struct student{
	int rollno;
	char name[20];
	float sgpa;
};
void input(struct student *);
void print(struct student *);
void desc(struct student *,int );
int main(){
	int size;
	printf("How many studeny detail you want to enter : ");
	scanf("%d",&size);
	struct student s[size];

	//input
	for(int i = 0 ; i < size ; i++){
		printf("\nEnter detail of %d student : \n",i+1);
		input(s+i);
	}

	//print
	printf("Entered data..\n");
	printf("|Rollno|Name                |SGPA|\n");
	for(int i = 0 ; i < size ; i++){
		print(&*(s+i));
	}

	//sort
	desc(s,size);
	//print
	printf("\n\nDescending order \n");
	printf("|Rollno|Name                |SGPA  |\n");
	for(int i = 0 ; i < size ; i++){
		print(&*(s+i));
	}

	return 0;
}



void input(struct student *s){
	printf("Enter Rollno : ");
	scanf("%d",&s->rollno);
	printf("Enter Name : ");
	scanf("%s",s->name);
	printf("Enter SGPA : ");
	scanf("%f",&s->sgpa);
}

void print(struct student *s){
	printf("|%-6d|%-20s|%-.4f|\n",s->rollno,s->name,s->sgpa);
	return;
}

void desc(struct student *s , int size){
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if((s+i)->sgpa > (s+j)->sgpa){
				struct student temp = *(s+j);
				*(s+j) = *(s+i);
				*(s+i) = temp;
			}
		}
	}
	return;
}


