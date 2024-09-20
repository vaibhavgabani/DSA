/*
 * P09.c
 *
 *  Created on: 01-Aug-2024
 *      Author: root
 */
#include<stdio.h>
void address_1d();
void address_2d();
int main(){
	printf("9. Write a program to find the location of element within one dimensional and two dimensional array.\n\n");
	printf("Address of 1D : \n\n\n");
	address_1d();
	printf("Address of 2D : \n\n\n");
	address_2d();
	return 0;
}

void address_1d(){
	int size, position, ba;

		printf("Enter Size of 1d array : ");
		scanf("%d",&size);
		int arr_1d[size];
		ba=&arr_1d[0];

		for(int i = 0 ; i < size ; i++){
			printf("position  of : %d address  is : %u\n",i,&arr_1d[i]);
		}

		printf("Enter Position which address you want : ");
		scanf("%d",&position);

		if(position >= size){
			printf("Enter valid position\n");
			return;
		}
		int address_1d = ba + (4 * (position - 0));

		printf("Address of : %d is : %u\n",position , address_1d);
		return;
}
void address_2d(){
	int  m , n , position_i , position_j;
		printf("Enter m for 2d array : ");
		scanf("%d",&m);
		printf("Enter n for 2d array : ");
		scanf("%d",&n);
		int arr[m][n];
		int ba = &arr[0][0];
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				printf("position  of : [%d][%d] address  is : %u\n",i,j,&arr[i][j]);
			}
		}

		printf("Enter Position which address you want in [m] : ");
		scanf("%d",&position_i);
		printf("Enter Position which address you want in [n] : ");
		scanf("%d",&position_j);

		if(position_i >= m || position_j >= n){
			printf("Enter valid position\n");
			return;
		}
//		int address_2d = ba + (4 * ((m*n)* position_i  + position_j ));
		int address_2d = ba + 4 * (n * position_i  + position_j );
		printf("Address of : [%d][%d] is : %u", position_i , position_j , address_2d);
}


