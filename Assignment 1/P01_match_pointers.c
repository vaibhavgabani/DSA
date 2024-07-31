/*
 * P01.c
 *
 *  Created on: 25-Jul-2024
 *      Author: root
 */


#include<stdio.h>
int main(){
	int size = 5;
//	printf("Enter Size : ");
//	scanf("%d",&size);
	int arr[size];

	int *ptr1 = arr;
	int *ptr2 = arr;

	if(ptr1 == ptr2){
		printf("Both are at same Location\n");
	} else {
		printf("Both are not at same Location\n");
	}

	ptr2++;

	if(ptr1 == ptr2){
			printf("Both are at same Location\n");
		} else {
			printf("Both are not at same Location\n");
		}

	return 0;
}
