/*
 * P08.c
 *
 *  Created on: 30-Jul-2024
 *      Author: root
 */
#include<stdio.h>

int main(){
    int rollno , subject , marks = 1;
    printf("Enter total number of student : ");
    scanf("%d",&rollno);
    printf("Enter total number of Subject : ");
    scanf("%d",&subject);
    int arr[rollno][subject][marks];

    //input
    for(int i = 0 ; i < rollno ; i++){
        printf("\nEnter data in rollno [%d] : \n",i+1);
        for(int j = 0 ; j < subject ; j++){
            for(int k = 0 ; k < marks ; k++){
                printf("Enter Marks in %d subject : ",(101+j));
                scanf("%d",&arr[i][j][k]);
            }
        }
    }
    //print
    for(int i = 0 ; i < rollno ; i++){
        printf("\nEntered data in rollno [%d] : \n",i+1);
        printf("-------------------------\n");
        printf("|Subject\t|Marks\t|\n");
        printf("-------------------------\n");
        for(int j = 0 ; j < subject ; j++){
            for(int k = 0 ; k < marks ; k++){
                printf("|%d\t\t|%d\t|",101+j,arr[i][j][k]);
            }
            printf("\n");
        }
        printf("-------------------------\n");
    }
    return 0;
}



