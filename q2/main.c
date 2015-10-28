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
    int ch = 0;
    char c,result;
    struct timespec start,end;
    double cpu_time1;
    int i=0;
    char charBank[27] = "abcdefghijklmnopqrstuvwxyz";
    char str[26 * 1 + 1];
    int len = 0;
    srand(time(NULL));
    while(i<=26*1) {
        if(rand() & 1) {
            str[len++] = charBank[i];
        }
        i++;
    }
    str[len++] = '\0';
    printf("%s\n",str);

    while(1) {
        printf("<1>input a character <2>Exit : ");
        scanf("%d",&ch);
        if(ch == 2) {
            break;
        } else if(ch==1) {
            printf("input a character: ");
            scanf(" %c",&c);
#if defined(ITER)
            clock_gettime(CLOCK_REALTIME, &start);
            result = Smallest_Character_Iterative(str,c);
            clock_gettime(CLOCK_REALTIME, &end);
            cpu_time1 = diff_in_second(start,end);
#endif
#if defined(RECUR)
            clock_gettime(CLOCK_REALTIME, &start);
            result = Smallest_Character_Recursive(str,c);
            clock_gettime(CLOCK_REALTIME, &end);
            cpu_time1 = diff_in_second(start,end);
#endif
#if defined(RECUR)
            printf("result = [ %c ]\n",result);
            printf("execution time of Recursive() %.10lf sec\n",cpu_time1);
#endif

#if defined(ITER)
            printf("result = [ %c ]\n",result);
            printf("execution time of Iterative() %.10lf sec\n",cpu_time1);
#endif

        }
    }

    return(0);
}
