/*
 * P02.c
 *
 *  Created on: 25-Jul-2024
 *      Author: root
 */


#include<stdio.h>

int xlen(char *);


int main() {
    char str[20];
    printf("Enter String : ");
    scanf("%s",str);
    printf("size of '%s' is : %d",str,xlen(str));
    return 0;
}

int xlen(char *ptr) {
    int size = 0;
    while(*(ptr+size) != '\0'){
    	size++;
    }
	return size;
}


