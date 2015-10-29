#include<stdio.h>

int MaxSubArray_Iterative(int A[],int n)
{
    int max_so_far = 0,max_ending_here = 0;
    int i,head = 0,tail = 0;
    for(i=0 ; i<n ; i++) {
        max_ending_here += A[i];
        if(max_ending_here < 0) {
            max_ending_here = 0;
            head = 0;

        } else if((max_ending_here >= 0) && (head == 0)) {
            head = i;
        }
        if(max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            tail = i;
        }
    }
    printf("head = %d ,tail = %d\n",head,tail);
    return(max_so_far);
}

