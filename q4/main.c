#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<string.h>


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
    char line[64],*str;
    int A[]= {-2,1,-3,4,-1,2,1,-5,4};
    int sum;
    struct timespec start,end;
    double cpu_time1;
    //FILE *fp;
    int i=0;
    for(i=0; i<sizeof(A)/sizeof(A[0]); i++) {
        printf("%d\n",A[i]);
    }
#if defined(ITER)
    clock_gettime(CLOCK_REALTIME, &start);
    sum = MaxSubArray_Iterative(A,(sizeof(A)/sizeof(A[0])));
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif
#if defined(RECUR)
    clock_gettime(CLOCK_REALTIME, &start);
    sum = MaxSubArray_Recursive(A,(sizeof(A)/sizeof(A[0])));
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start,end);
#endif

#if defined(ITER)
    printf("sum = [ %d ]\n",sum);
    printf("execution time of iterative() %.10lf sec\n",cpu_time1);
#endif
#if defined(RECUR)
    printf("sum = [ %d ]\n",sum);
    printf("execution time of recursive() %.10lf sec\n",cpu_time1);
#endif


    return(0);
}
