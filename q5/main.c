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

    ListNode *head = NULL,*begin = NULL;
    int size = 8,cycle_begin = 5;
    struct timespec start,end;
    double cpu_time1;
    head = Build_Linklist(head,size,cycle_begin);
    Linklist_Traversal(head,size);
    printf("\n");
#if defined(RECUR)
    clock_gettime(CLOCK_REALTIME, &start);
    begin = DetectCycle_Recursive(head);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif


#if defined(ITER)
    clock_gettime(CLOCK_REALTIME, &start);
    begin  = DetectCycle_Iterative(head);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif

#if defined(RECUR)
    if(begin == NULL) {
        printf("There is no cycle in this Linklist\n");
    } else {
        printf("cycle begin value = %d\n",begin->data);
        printf("execution time of DetectCycle_Recursive() %.10lf sec\n",cpu_time1);
    }
#endif
#if defined(ITER)
    if(begin == NULL) {
        printf("There is no cycle in this Linklist\n");
    } else {
        printf("cycle begin value = %d\n",begin->data);
        printf("execution time of DetectCycle_Iterative() %.10lf sec\n",cpu_time1);
    }
#endif

    return(0);
}
