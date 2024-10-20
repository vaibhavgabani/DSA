#include<stdio.h>
#include<stdlib.h>

struct node {
    /* data */
    char str[20];
    struct node *next;
}*first = NULL , *last = NULL , *temp = NULL , *curr = NULL;

int is_empty();
void insert_first();
void insert_bit();
void travers();
void delete_last();

int main(){
    int choice;
    while(1){
        printf("\n\nPress 1 : Insert first\nPress 2 : Travers\nPress 3 : insert_bit\nPress 4 : delete last\nPress 0 : exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            insert_first();
            break;
        case 2:
            travers();
            break;
        case 3:
            insert_bit();
            break;
        case 4:
            delete_last();
        break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return -1;
}

int is_empty(){
    return first == NULL;
}

void delete_last(){
    if(is_empty()){
        printf("List is empty!!!\n"); 
        return;
    }
    
    temp = last;

    if(first == last){
        first = last = temp;
    } else {
        curr = first;
        while(curr->next != last){
            curr = curr->next;
        }
        curr->next = NULL;
        last = curr;
    }    
    free(temp);
    return;
}

void insert_first(){
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Name  : ");
    scanf(" %s",temp->str);
    temp->next = first;
    if(is_empty()){
        first = last = temp;
    } else {
        first = temp;
    }
    return;
}

void insert_bit(){
    if(is_empty()){
        printf("Stack is empty : ");
        return;
    }
    int index , cnt = 1;
    curr = first;
    printf("After whilch element you want to enter ?  : ");
    scanf("%d",&index);
    while(curr->next != NULL && cnt < index){
        curr = curr->next;
        cnt++;
    } 
    if(cnt == index){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter Name  : ");
        scanf(" %s",temp->str);
        temp->next = curr->next;
        curr->next = temp;
        if(curr == last){
           last = temp;
        }
    } else {
        printf("Index out of range! Valid index: 1 to %d\n", cnt);  // Updated message
    }
}

void travers(){
    if (is_empty()) {  // Added check for empty list
        printf("List is empty!\n");
        return;
    }
    curr = first;
    while(curr != NULL){
        printf("%s ",curr->str);
        curr = curr->next;
    }
    return;
}