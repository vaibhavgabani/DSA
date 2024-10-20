#include<stdio.h>
#include<stdlib.h>

struct node{
    int rolllno;
    struct node *left;
    struct node *right;
}*first,*last,*tmp,*curr;

void insert_first();
void insert_last();
void insert_after();
int empty();
void delete_first();
void delete_last();
void trace();
void  delete_after();
void  delete_rollno();
int main() {
    int choice;
    do {
        // Display the menu
        printf("\n\n\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at After\n");
        printf("4. Display List\n");
        printf("5. Delete first\n");
        printf("6. Delete last\n");
        printf("7. Delete after\n");
        printf("8. Delete rollno\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n\n");
        switch (choice) {
            case 1:
                insert_first(); // Call insert function
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_after();
                break;        
            case 4:
                trace(); // Call display function
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_last();
                break;
            case 7:
                delete_after(); 
                break;
            case 8:
                delete_rollno();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0); // Loop until user chooses to exit

    return 0;
}


int empty(){
    return first == NULL;
}

void trace(){
    if(empty()){
        printf("Liked list is Empty!!!\n");
        return;
    }
    curr = first;
    do{
        printf("|%d|---",curr->rolllno);
        curr = curr->right;
    }while(curr != first);
}

void insert_first(){
    tmp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Rollno : ");
    scanf("%d",&tmp->rolllno);
    tmp->right = first;
    if(empty()){
        first = last = tmp; 
    } else {
        first->left = tmp;
        first = first->left;
    }
    last->right = first;
    first->left = last;
    return;
}

void insert_last(){
    tmp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Rollno : ");
    scanf("%d",&tmp->rolllno);
    tmp->left = last;
    if(empty()){
        first = last = tmp;
    } else {
        last->right = tmp;
        last = tmp;
    }
    last->right = first;
    first->left = last;
}

void insert_after(){
    if(empty()){
        printf("Liked list is Empty!!!\n");
        return;
    }
    int index , cnt = 1;
    printf("After which index you want to add  : ");
    scanf("%d",&index);
    curr = first;
    
    while(curr->right != first && cnt < index){
        curr = curr->right;
        cnt++;
    } 

    if(cnt == index){
        tmp = (struct node*)malloc(sizeof(struct node));
        printf("Enter Rollno : ");
        scanf("%d",&tmp->rolllno);
        if(curr == last){
            last->right = tmp;
            tmp->left = last;
            last = last->right;
            last->right = first;
            first->left = last;
        } else {
            tmp->right = curr->right;
            tmp->left = curr;
            curr->right = tmp;
            tmp->right->left = tmp;
        }
    } else {
        printf("Enter valid index !!!\n");
    }
}

void delete_first(){
    if(empty()){
        printf("Liked list is Empty!!!\n");
        return;
    }
    tmp = first;
    if(first == last){
        first = last = NULL;    
    } else {
        first = first->right;
        last->right = first;
        first->left = last;
    }
}

void delete_last(){
    if(empty()){
        printf("Liked list is Empty!!!\n");
        return;
    }
    curr = last;
    if(first == last){
        first = last = NULL;
    } else {
        last = last->left;
        last->right = first;
        first->left = last;
    }
}

void  delete_after(){
    if(empty()){
        printf("Liked list is Empty!!!\n");
        return;
    }
    int index , cnt = 1;
    printf("Enter index which you want to delete : ");
    scanf("%d",&index);
    tmp = first;
    
   while(tmp->right != first && cnt < index){
        tmp = tmp->right;
        cnt++;
   }

    if(cnt == index){
        if(first == last){
            first = last = tmp;
        } else if(tmp == first){
            first = first->right;
            last->right = first;
            first->left = last;
        } else if(tmp == last){
            last = last->left;
            last->right = first;
            first->left = last;
        } else {
          tmp->right->left = tmp->left;
          tmp->left->right = tmp->right;
        }
        free(tmp);
    } else {
        printf("Enter valid index!!!\n");
    }

}

void delete_rollno(){
    if(empty()){
        printf("Liked list is Empty!!!\n");
        return;
    }
    int rno , flag = 0;
    printf("Enter your rollno : ");
    scanf("%d",&rno);
    tmp = first;
    do{
        curr = tmp;
        if(tmp->rolllno == rno){
            flag = 1;
            break;
        }
        tmp = tmp->right;
    }while(tmp != first);

    if(flag == 1){
        if(first == last){
            first = last = NULL;
        } else if(tmp == first){
            first = first->right;
            first->left = last;
            last->right = first;
        } else if(tmp == last){
            last = last->left;
            first->left = last;
            last->right = first;
        } else {
            tmp->right->left = tmp->left;
            tmp->left->right = tmp->right;
        }
        free(tmp);
    } else {
        printf("Enter valid rolllno!!!\n");
    }
}