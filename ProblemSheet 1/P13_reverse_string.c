/*
 * P13.c
 *
 *  Created on: 29-Jul-2024
 *      Author: root
 */
#include <stdio.h>

int main() {
	int max = 3;
    char stack1[max], stack2[max] ;

    // Enter values into stack1
    printf("Enter value for stack1 at position  : ");
    scanf("%s",stack1);


    //rev
    for(int i = max - 1 , j = 0 ; i >= 0 , j < max ; i-- , j++){
    	stack2[j]  =  stack1[i];
    }

    printf("Reverce Stack is : %s",stack2);
    return 0;
}




