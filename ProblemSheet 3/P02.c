
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first = NULL , *last = NULL , *temp = NULL , *curr = NULL;

int is_empty(){
    return first == NULL;
}

void insert_first(){
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Value  : ");
    scanf("%d",&temp->data);

    temp->next = first;
    if(is_empty()){
        first = last = temp;
    } else {
        first = temp;
    }
    last->next = first;
}

void insert_last(){
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Value  : ");
    scanf("%d", &temp->data);

    temp->next = first;

    if(is_empty()) {
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }

    last->next = first;
}

void insert_bt(){
    if(is_empty()){
        printf("Linked list is empty!!!\n");
        return;
    }
    int index , cnt = 1;
    printf("Enter index : ");
    scanf("%d",&index);
    curr = first;
    while(curr->next != first && cnt < index){
        curr = curr->next;
        cnt++;
    }
    if(cnt == index){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter Value  : ");
        scanf("%d",&temp->data);
        temp->next = curr->next;
        curr->next = temp;
        if(curr == last){
            last = temp;
            last->next = first;
        }
    } else {
        printf("Enter Valid index!!!\n");
    }
}

void delete_first(){
    if(is_empty()){
        printf("Linked list is empty!!!\n");
        return;
    }
    temp = first;
    if(first == last){
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }
    free(temp);
}

void delete_last(){
    if(is_empty()){
        printf("Linked list is empty!!!\n");
        return;
    }
    temp = last;
    if(first == last){
        first = last = NULL;
    } else {
        curr = first;
        while(curr->next != last){
            curr = curr->next;
        }
        last = curr;
        last->next = first;
    }
    free(temp);
}

void delete_bt(){
    if(is_empty()){
        printf("Linked list is empty!!!\n");
        return;
    }
    int index , cnt = 1;
    printf("Enter index : ");
    scanf("%d",&index);
    temp= first;
    while(temp->next != first && cnt < index){
        curr = temp;
        temp = temp->next;
        cnt++;
    }
    if(cnt == index){
        if(first == last){
            first = last = NULL;
        } else if (temp == first){
            first = first->next;
            last->next = first;
        } else if(temp == last){
            last = curr;
            last->next = first;
        } else {
            curr->next = temp->next;
        }
        free(temp);
    } else {
        printf("Enter Valid index\n");
    }
}

void traversal(){
    if(is_empty()){
        printf("Linked list is empty!!!\n");
        return;
    }
    printf("\ntemp = %d\n",temp->data);
    curr = first;
    do{
        printf("%d ",curr->data);
        curr = curr->next;
    }while(curr != first);
}

void sort_a(){
    if (is_empty()) {
        printf("Linked list is empty!!!\n");
        return;
    }

    for (struct node *i = first; i->next != first; i = i->next) {
        for (struct node *j = i->next; j != first; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void sort_d(){
    if (is_empty()) {
        printf("Linked list is empty!!!\n");
        return;
    }

    for (struct node *i = first; i->next != first; i = i->next) {
        for (struct node *j = i->next; j != first; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}


int main(){
    int choice;
        while(1){
            printf("\n\nPress 1: Insert_first\nPress 2: Insert Last\nPress 3: Insert between\nPress 4: Traverse\nPress 5: Delete first\nPress 6: Delete Last\nPress 7: Delete Between\nPress 8: Sort in Accending Order\nPress 9: sort in Decending Order\nPress 0: Exit\n\nEnter your choice : ");
            scanf("%d",&choice);
            switch(choice){
            case 1:
                insert_first();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_bt();
                break;
            case 4:
                traversal();
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_last();
                break;
            case 7:
                delete_bt();
                break;
            case 8:
                sort_a();
                break;
            case 9:
                sort_d();
                break;
            case 0:
                return 0;
            }
        }
    return -1;
}



