#include <stdio.h>

int main() {
	int max = 3;
    int stack1[max], stack2[max] , stack3[max * 2];

    // Enter values into stack1
    for (int i = 0; i < max; i++) {
        printf("Enter value for stack1 at position %d: ", i + 1);
        scanf("%d",&stack1[i]);
    }

    // Enter values into stack2
    printf("\n\n");
    for (int i = 0; i < max; i++) {
        printf("Enter value for stack2 at position %d: ", i + 1);
        scanf("%d",&stack2[i]);
    }

    printf("stack 1\n");
    for(int i = max -1 ; i >= 0 ; i--){
        printf("| %d |\n",stack1[i]);
    }

    printf("stack 1\n");
    for(int i = max - 1 ; i >= 0 ; i--){
        printf("| %d |\n",stack2[i]);
    }

    int i = (max*2)-1 , j = (max-1);
    while(j >= 0){
    	stack3[i--] = stack1[j];
    	stack3[i--] = stack2[j];
    	j--;
    }


    printf("stack 3\n");
        for(int i = (max*2)-1 ; i >= 0 ; i--){
            printf("| %d |\n",stack3[i]);
        }
    return 0;
}


