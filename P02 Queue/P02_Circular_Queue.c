#include <stdio.h>
#define max 6
int cq[max];
int f = -1;
int r = -1;

int empty() {
    return r == -1 && f == -1;
}
int full() {
    return (r == max - 1 && f == 0) || (r == f - 1);
}
void front() {
    if (empty()) {
        printf("----> Queue is Empty !");
        return;
    }
    printf("\nFront Element = %d\n", cq[f]);
    return;
}
void rear() {
    if (empty()) {
        printf("----> Queue is Empty !");
        return;
    }
    printf("\nRear Element = %d\n", cq[r]);
    return;
}

void enqueue() {
    if (full()) {
        printf("----> Queue is Full ! ");
        return;
    } else if (empty()) {
        f = r = 0;
    } else if (r == max - 1 && f > 0) {
        r = 0;
    } else {
        r++;
    }

    printf("Enter Value you want to Enqueue : ");
    scanf("%d", &cq[r]);
    printf("Element %d Enqueued Successfully !\n", cq[r]);
}

void dequeue() {
    if (empty()) {
        printf("----> Queue is Empty !");
        return;
    }

    printf("Element %d is Dequeued Successfully !\n", cq[f]);

    if (r == f) {
        r = -1;
        f = -1;
    } else if (f == max - 1) {
        f = 0;
    } else {
        f++;
    }
}

void traverse() {
    if (empty()) {
        printf("----> Queue is Empty ! ");
        return;
    } else if (r >= f) {
        printf("Queue : ");
        for (int i = f; i <= r; i++) {
            printf("%d ", cq[i]);
        }
    } else {
        printf("Queue : ");
        for (int i = f; i <= max - 1; i++) {
            if (cq[i] != 0) {
                printf("%d ", cq[i]);
            }
        }
        for (int i = 0; i <= r; i++) {
            if (cq[i] != 0) {
                printf("%d ", cq[i]);
            }
        }
    }
}

int main() {
    int c;
    do {
        printf("\n\n1. Enqueue \n2. Dequeue \n3. Traverse \n4. Rear Element \n5. Front Element \n6. Exit \n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &c);

        switch (c) {
            case 1: printf("\n\n"); enqueue(); break;
            case 2: printf("\n\n"); dequeue(); break;
            case 3: printf("\n\n"); traverse(); break;
            case 4: printf("\n\n"); rear(); break;
            case 5: printf("\n\n"); front(); break;
            case 6: printf("\nExited !!!\n"); return 1;
            default: printf("\n\nInvalid Input\n"); break;
        }
    } while (1);
    return 0;
}
