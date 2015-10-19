#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "Binary_tree.h"

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

    Tree_Node *root = NULL;
    struct timespec start,end;
    double cpu_time1;
    root = Build_Binary_Tree(root);
    Inorder_traversal(root);
    printf("\n");
#if defined(RECUR)
    clock_gettime(CLOCK_REALTIME, &start);
    Flatten_Recursive(root);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif
#if defined(ITER)
    clock_gettime(CLOCK_REALTIME, &start);
    Flatten_Iterative(root);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif
    Inorder_traversal(root);
    printf("\n");

#if defined(RECUR)
    printf("execution time of Flatten_Recursive() %.10lf sec\n",cpu_time1);
#endif
#if defined(ITER)
    printf("execution time of Flatten_Iterative() %.10lf sec\n",cpu_time1);
#endif
    return(0);
}
