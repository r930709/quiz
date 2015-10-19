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
    char line[64],*str,ser[64];
    int ch = 0;
    char c,result;
    struct timespec start,end;
    double cpu_time1;
    FILE *fp;
    int i=0;
    fp = fopen("character_series.txt","r");
    fgets(line,sizeof(line),fp);
    str = strtok(line,",");
    while(str!=NULL) {
        ser[i] = str[0];
        i++;
        str = strtok(NULL,",");
    }
    ser[i] = '\0';
    i=0;
    while(ser[i]!='\0') {
        printf("show %c\n",ser[i]);
        i++;
    }
    while(1) {
        printf("<1>input a character <2>Exit : ");
        scanf("%d",&ch);
        if(ch == 2) {
            break;
        } else if(ch==1) {
            printf("input a character: ");
            scanf(" %c",&c);
            /*
            #if defined(RECUR)
            	clock_gettime(CLOCK_REALTIME, &start);
                Flatten_Recursive(root);
            	clock_gettime(CLOCK_REALTIME, &end);
            	cpu_time1 = diff_in_second(start,end);
            #endif
            */
#if defined(ITER)
            clock_gettime(CLOCK_REALTIME, &start);
            result = Smallest_Character_Iterative(ser,c);
            clock_gettime(CLOCK_REALTIME, &end);
            cpu_time1 = diff_in_second(start,end);
#endif
            /*
            #if defined(RECUR)
            	printf("execution time of Flatten_Recursive() %.10lf sec\n",cpu_time1);
            #endif
            */
#if defined(ITER)
            printf("result = [ %c ]\n",result);
            printf("execution time of Flatten_Iterative() %.10lf sec\n",cpu_time1);
#endif
        }
    }

    return(0);
}
