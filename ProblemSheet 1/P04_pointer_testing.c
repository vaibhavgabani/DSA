/*
 * P04.c
 *
 *  Created on: 25-Jul-2024
 *      Author: root
 */


#include<stdio.h>
int main(){
	int arr[4] = {10,20,30,40};
	int *p = arr;

	*p++;
	printf("Pearformaing *p++ : %d\n",*p);

	p--;
	printf("Pearformaing p-- : %d\n",*p);

	*++p;
	printf("Pearformaing *++p : %d\n",*p);
	return 0;
}
