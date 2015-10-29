#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "Linklist.h"

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}




int main()
{

    ListNode *head = NULL;
    int size = 8,m = 1,n = 6;
    struct timespec start,end;
    double cpu_time1;
    head = Build_Linklist(head,size);
    Linklist_Traversal(head);
    printf("\n");

#if defined(RECUR)
    clock_gettime(CLOCK_REALTIME, &start);
    head = Reversebetween_Recursive(head,m,n);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif


#if defined(ITER)
    clock_gettime(CLOCK_REALTIME, &start);
    head  = Reversebetween_Iterative(head,m,n);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif


#if defined(RECUR)
    Linklist_Traversal(head);
    printf("\nexecution time of Reversebetween_Recursive() %.10lf sec\n",cpu_time1);

#endif

#if defined(ITER)
    Linklist_Traversal(head);
    printf("\nexecution time of Reversebetween_Iterative() %.10lf sec\n",cpu_time1);
#endif

    return(0);
}
