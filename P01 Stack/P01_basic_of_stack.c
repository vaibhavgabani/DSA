#include<stdio.h>
#define max 5 // define stack size here
int stack_arr[max];
int top = -1;

void push();
void pop();
void peep();
void travel();

int main(){
    int choice;
    do{
        printf("\n\nPress 1 : Push\nPress 2 : Pop\nPress 3 : Peep\nPress 4 : Travel\nPress 5 : Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\n\n");
                push();
                
                break;
            case 2:
                printf("\n\n");
                pop();
                break;
            case 3:
                printf("\n\n");
                peep();
                break;
            case 4:
                printf("\n\n");
                travel();
                break;
            case 5:
                return 1;
            default:
                printf("Enter Valid input!!!\n");
                break;
        }
    }while(1);
    
    return 0;
}

void push(){
    if(top == max - 1){
        printf("Stack is Full!!!\n");
        return;
    }
    top++;
    printf("Enter Element : ");
    scanf("%d",&stack_arr[top]);
    printf("\nElement Added Sucessfully!..");
    return;
}

void pop(){
    if(top == -1){
        printf("Stack is Empty!!!");
        return;
    }
    stack_arr[top] = 0;
    top--;
    printf("\nElement Remove Sucessfully!..");
}

void peep(){
    if(top == -1){
        printf("Stack is Emplty!!!");
        return;
    }
    printf("| %d |\n",stack_arr[top]);
    return;
}

void travel(){
    if(top == -1){
        printf("Stack is Empty!!!\n");
        return;
    }
    for(int i = top ; i >= 0 ; i--){
        printf("| %d |\n",stack_arr[i]);
    }
    printf("-----");
    return;
}
