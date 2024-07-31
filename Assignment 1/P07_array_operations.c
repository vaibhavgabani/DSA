/*
 * P07.c
 *
 *  Created on: 26-Jul-2024
 *      Author: root
 */


#include<stdio.h>

void xprint_1d(int [], int);
void xinput_1d(int [], int);
int sum_of_1d(int [], int);
void xsort_1d_asc(int [], int);
void xsort_1d_dsc(int [], int);
void rev_1d(int [],int );
void rev_2d(int x , int y , int arr[x][y]);
void input_2d(int x , int y ,int arr[x][y]);
void print_2d(int x , int y ,int arr[x][y]);
int sum_of_2d(int x , int y ,int arr[x][y]);
void sort_2d_asc(int x , int y , int arr[x][y]);
void sort_2d_dsc(int x , int y , int arr[x][y]);

int main() {
    int size , x , y;
    //input of 1d
    printf("Enter Size of 1d array : ");
    scanf("%d",&size);
    int arr[size];
    xinput_1d(arr, size);

    //input of 2d
    printf("Enter the size of x of 2d array : ");
    scanf("%d",&x);
    printf("Enter the size of y of 2d array : ");
    scanf("%d",&y);
    int arr2[x][y];
    input_2d(x,y,arr2);


    //print
    printf("\nEntered value in 1d array : ");
    xprint_1d(arr,size);
    printf("\n\nEntered value in 2d array : \n");
    print_2d(x,y,arr2);

    //desc
    printf("\nsort in desc of 1d array : ");
    xsort_1d_dsc(arr,size);
	xprint_1d(arr,size);
	printf("\n\nsort in desc of 2d array : \n");
	sort_2d_dsc(x,y,arr2);
	print_2d(x,y,arr2);


	//asc
	printf("\nsort in asc of 1d array : ");
	xsort_1d_asc(arr,size);
	xprint_1d(arr,size);
	printf("\n\nsort in asc of 2d array : \n");
	sort_2d_asc(x,y,arr2);
	print_2d(x,y,arr2);

	//rev
	printf("\nsort in rev of 1d array : ");
    rev_1d(arr,size);
	xprint_1d(arr,size);
	printf("\n\nsort in rev of 2d array : \n");
	rev_2d(x,y,arr2);
	print_2d(x,y,arr2);

	//sum
	printf("\nSum of 1d arr is : %d",sum_of_1d(arr,size));
	printf("\n\nSum of 2d arr is : %d",sum_of_2d(x,y,arr2));
    return 0;
}

void xsort_1d_asc(int arr[], int size){
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(arr[i] < arr[j]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}



void xsort_1d_dsc(int arr[], int size){
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(arr[i] > arr[j]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

void xprint_1d(int arr[], int size){
	for(int j = 0 ; j < size ; j++){
		printf("%d\t",arr[j]);
	}
}

void xinput_1d(int arr[], int size){
	for(int j = 0 ; j < size ; j++){
		printf("Enter value at %d : ",j+1);
		scanf("%d",&arr[j]);
	}
}

int sum_of_1d(int arr[], int size){
	int sum = 0;
	for(int j = 0 ; j < size ; j++){
		sum += arr[j];
	}
	return sum;
}

void rev_1d(int arr[],int size){
	int i = 0 , j = (size - 1);

	while(i < j){
	 int temp = arr[i];
	 arr[i] = arr[j];
	 arr[j] = temp;
	 i++;
	 j--;
	}
	return;
}
void input_2d(int x , int y ,int arr[x][y]){
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < y ; j++){
			printf("Enter value at [%d][%d] : ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
}
void print_2d(int x , int y ,int arr[x][y]){
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < y ; j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
void sort_2d_asc(int m , int n , int arr[m][n]){
	for(int i = 0 ; i < m ;i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < m ; k++){
				for(int z = 0 ; z < n ; z++){
					if(arr[i][j] < arr[k][z]){
						int temp = arr[k][z];
						arr[k][z] = arr[i][j];
						arr[i][j] = temp;
					}
				}
			}
		}
	}
}

void sort_2d_dsc(int m , int n , int arr[m][n]){
	for(int i = 0 ; i < m ;i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < m ; k++){
				for(int z = 0 ; z < n ; z++){
					if(arr[i][j] > arr[k][z]){
						int temp = arr[k][z];
						arr[k][z] = arr[i][j];
						arr[i][j] = temp;
					}
				}
			}
		}
	}
}

void rev_2d(int m , int n , int arr[m][n]){
	int *start = arr[0][0] ;
	int *end = arr[m-1][n-1];
	while(start > end){
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

}

int sum_of_2d(int x , int y ,int arr[x][y]){
	int sum = 0;
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < y; j++){
			sum += arr[i][j];
		}
	}
	return sum;
}
