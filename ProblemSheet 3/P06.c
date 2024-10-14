/*
 * P06.c
 *
 *  Created on: 08-Oct-2024
 *      Author: root
 */

#include<stdio.h>
#include<stdlib.h>
struct node{
    int rollno,sem,sub1,sub2,sub3,total;
    char name[20];
    struct node *next;
}*first = NULL , *last = NULL , *temp = NULL , *curr = NULL;

int empty(){
    if(first == NULL){
        return 1;
    }
    return 0;
}


void insert(){
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Rollno : ");
    scanf("%d",&temp->rollno);
    printf("Enter Name : ");
    scanf(" %s",temp->name);
    printf("Enter Sem : ");
    scanf("%d",&temp->sem);
    printf("Enter marks of Subject 1 : ");
    scanf("%d",&temp->sub1);
    printf("Enter marks of Subject 2 : ");
    scanf("%d",&temp->sub2);
    printf("Enter marks of Subject 3 : ");
    scanf("%d",&temp->sub3);
    temp->total = temp->sub1 + temp->sub2 + temp->sub3;
    temp->next = NULL;
    if(empty()){
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
    return;
}


void traversal() {
    if (empty()) {
        printf("Linked list is empty!!!\n");
        return;
    }

    curr = first;
    printf("| Rollno |        Name        | Sem | Subject 1  | Subject 2  | Subject 3  | Total |\n");
    printf("|--------|--------------------|-----|------------|------------|------------|-------|\n");

    while (curr != NULL) {
        printf("| %-6d | %-18s | %-3d | %-10d | %-10d | %-10d | %-5d |\n",
               curr->rollno, curr->name, curr->sem, curr->sub1, curr->sub2, curr->sub3, curr->total);
        curr = curr->next;
    }
}


void find_max(){
    if (empty()) {
        printf("Linked list is empty!!!\n");
        return;
    }
    for(struct node *i = first ; i != NULL ; i = i->next){
        for(struct node *j = first ; j != NULL ; j = j->next){
            if(i->total < j->total){
                temp = j;
            }
        }
    }
    curr = temp;
    printf("| Rollno |        Name        | Sem | Subject 1  | Subject 2  | Subject 3  | Total |\n");
    printf("|--------|--------------------|-----|------------|------------|------------|-------|\n");

        printf("| %-6d | %-18s | %-3d | %-10d | %-10d | %-10d | %-5d |\n",curr->rollno, curr->name, curr->sem, curr->sub1, curr->sub2, curr->sub3, curr->total);

}

void delete_by_rollno(){
    if(empty()){
        printf("Linked List is empty!!!\n");
        return;
    }
    int rno , flag = 0;
    printf("Enter Rollno which you want to delete : ");
    scanf("%d",&rno);
    temp = first;
    while(temp!= NULL){
        if(temp->rollno == rno){
            flag = 1;
            break;
        }
        curr = temp;
        temp = temp->next;
    }
    if(flag == 1){
        if(first == last){
            first = last = NULL;
        } else if(temp == first){
            first = first->next;
        } else if( temp == last){
            curr->next = NULL;
            last = curr;
        } else {
            curr->next = temp->next;
        }
        free(temp);
    } else {
        printf("Enter Valid Rollno!!!\n");
    }
}

int main(){
    int choice;
        while(1){
            printf("\n\nPress 1: insertion\nPress 2: Display\nPress 3: Delete base on rollno\nPress 4: higest makrs student\nPress 0: Exit\n\nEnter your choice : ");
            scanf("%d",&choice);
            switch(choice){
            case 1:
                insert();
                break;
            case 2:
                traversal();
                break;
            case 3:
                delete_by_rollno();
                break;
            case 4:
                find_max();
                break;
            case 0:
                return 0;
            }
        }
    return -1;
}
