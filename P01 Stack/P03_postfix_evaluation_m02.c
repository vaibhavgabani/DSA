#include<stdio.h>
#define max 20
int stack_arr[max];
int top = -1;

void push();
void div();
void mul();
void sub();
void sum();
int is_operator(char ch);
void postfix_evaluation();


int main(){
	postfix_evaluation();
	return 0;
}

void push(){
	if(top == max - 1){
		printf("Stack is Full!!!!\n");
		return;
	}
	top++;
	scanf("%d",&stack_arr[top]);
	return;
}

void sum(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 + num2;
	stack_arr[top] = ans;
}

void sub(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 - num2;
	stack_arr[top] = ans;
}

void mul(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 * num2;
	stack_arr[top] = ans;
}

void div(){
	if(top == -1 || top == 0){
		printf("sum will not apply!!!\n");
		return;
	}

	int num1 , num2;
	num2 = stack_arr[top];
	top--;
	num1 = stack_arr[top];
	int ans = num1 / num2;
	stack_arr[top] = ans;
}

int is_operator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
        return 1;
    }
    return 0;
}

void postfix_evaluation(){
    char str[50];
    printf("\nEnter your Postfix string : ");
    scanf("%s",str);
    for(int i = 0 ; str[i] != '\0' ; i++){
        if((is_operator(str[i])) == 1){
            if(i < 2) {
                printf("\n%c opration can't be done at %d ",str[i],i);
                printf("\n=================================");
                return;
            } else {
                if (str[i] == '+'){
                sum();
                } else if (str[i] == '-'){
                    sub();
                } else if (str[i] == '*'){
                    mul();
                } else if (str[i] == '/'){
                    div();
                }
            }
        } else {
            printf("\nEnter value of %c = ",str[i]);
            push();
        }
    }
    printf("\nFinal output = %d ",stack_arr[top]);
    top--;
    return;
}