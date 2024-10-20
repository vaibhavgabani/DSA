#include<stdio.h>
#define max 5
int r = -1 , f = 0;

struct q{
    int data , prio;
} queue[max] , tmp;

int full();
int empty();
void enqueue();
void dequeue();
void travers();
void sort();
int main(){
    int choice;
    while(1){
        printf("\n\n\nPress 1 : enqueue\n");
        printf("Press 2 : dequeue\n");
        printf("Press 3 : travers\n");
        printf("Press 0 : exit\n");
        printf("enter your choice here : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                enqueue();
                sort();
                break;
            case 2:
                dequeue();
                break;    
            case 3:
                travers();
                break;
            case 0:
                return 0;
            default:
                printf("Enter valid choice!!!\n");   
                break;     
        }
    }
    return -1;
}


int full(){
    return f == max - 1 && f == 0; 
}
int empty(){
    return r == -1 && f == 0;
}

void enqueue(){
    if(full()){
        printf("queue is full!!!\n");
        return;
    }
    r++;
    printf("Enter value : "); 
    scanf("%d",&queue[r].data);
    printf("Enter prority : "); 
    scanf("%d",&queue[r].prio);    
}

void dequeue(){
    if(empty()){
        printf("queue is empty\n");
        return;
    }
    if(r == f){
        r = -1 , f = 0;
    } else {
        f++;
    }
    printf("deueue secessfully!!!\n");
}

void travers(){
    if(empty()){
        printf("queue is empty\n");
        return;
    }
    for(int i = f  ; i <= r ; i++){
        printf("|%d %d| ",queue[i].data,queue[i].prio);
    }
}

void sort(){
    for(int i = f ; i <= r ; i++){
        for(int j = f ; j <= r ; j++){
            if(queue[i].prio <= queue[j].prio){
                tmp = queue[j];
                queue[j] = queue[i];
                queue[i] = tmp;         
            }
        }
    }
}