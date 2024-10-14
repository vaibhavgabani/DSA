/*
 * P07.c
 *
 *  Created on: 11-Oct-2024
 *      Author: root
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mnode {
    int num;
    char str[1];  // Adjusted size to 100 for string
    struct mnode *mnext;
} *mfirst = NULL, *mlast = NULL;

struct inode {
    int idata;
    struct inode *inext;
} *ifirst = NULL, *ilast = NULL;

struct cnode {
    char cdata[1];  // Adjusted size to 100 for string
    struct cnode *cnext;
} *cfirst = NULL, *clast = NULL;

int mempty() {
    return mfirst == NULL;
}

int iempty() {
    return ifirst == NULL;
}

int cempty() {
    return cfirst == NULL;
}

void insert_after() {
    struct mnode *mtemp = (struct mnode *)malloc(sizeof(struct mnode));
    printf("Enter Number data: ");
    scanf("%d", &mtemp->num);
    printf("Enter String data: ");
    scanf("%s", mtemp->str);

    insert_inode(mtemp->num);
    insert_cnode(mtemp->str);

    if (mempty()) {
        mfirst = mlast = mtemp;
    } else {
        mlast->mnext = mtemp;
        mlast = mtemp;
    }
}

void insert_inode(int data) {
    struct inode *itemp = (struct inode *)malloc(sizeof(struct inode));
    itemp->idata = data;
    itemp->inext = NULL;  // Ensured inext is initialized to NULL

    if (iempty()) {
        ifirst = ilast = itemp;
    } else {
        ilast->inext = itemp;
        ilast = itemp;
    }
}

void insert_cnode(char data[1]) {
    struct cnode *ctemp = (struct cnode *)malloc(sizeof(struct cnode));  // Changed to cnode
    strcpy(ctemp->cdata, data);
    ctemp->cnext = NULL;

    if (cempty()) {
        cfirst = clast = ctemp;
    } else {
        clast->cnext = ctemp;
        clast = ctemp;
    }
}

void transfer_and_travers() {
    struct mnode *mcurr = mfirst;
    while (mcurr != NULL) {
        printf("|%d %s|---", mcurr->num, mcurr->str);
        mcurr = mcurr->mnext;
    }
    printf("\n\n");

    struct inode *icurr = ifirst;
    while (icurr != NULL) {
        printf("|%d|---", icurr->idata);
        icurr = icurr->inext;
    }
    printf("\n\n");

    struct cnode *ccurr = cfirst;
    while (ccurr != NULL) {
        printf("|%s|---", ccurr->cdata);
        ccurr = ccurr->cnext;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\nPress 1: Insert \nPress 2: Travers\nPress 0: Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_after();
                break;
            case 2:
                transfer_and_travers();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return -1;
}
