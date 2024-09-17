/*
 * P03.c
 *
 *  Created on: 25-Jul-2024
 *      Author: root
 */


#include<stdio.h>

int min(int *, int);
int max(int *, int);

int main() {
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d values:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Enter value at [%d] : ", i+1);
        scanf("%d", &arr[i]);
    }


    printf("min value is : %d & max value is : %d\n", min(arr, size), max(arr, size));

    return 0;
}

int min(int *ptr, int size) {
    int min_value = *ptr;
    for(int i = 1; i < size; i++) {
        if(ptr[i] < min_value) {
            min_value = ptr[i];
        }
    }

    return min_value;
}

int max(int *ptr, int size) {
    int max_value = *ptr;

    for(int i = 1; i < size; i++) {
        if(ptr[i] > max_value) {
            max_value = ptr[i];
        }
    }

    return max_value;
}
