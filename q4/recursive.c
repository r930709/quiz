#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int head = 0,tail=0;

int max_2(int a,int b)
{
    return((a>b)?a:b);
}
int max_3(int a,int b,int c)
{
    return(max_2(max_2(a,b),c));
}
int maxCrossingSum(int arr[],int l,int m,int r)
{
    int sum=0;
    int left_sum = INT_MIN;

    for(int i =m; i>=l ; i--) {
        sum = sum+arr[i];
        if(sum > left_sum) {
            left_sum = sum;
            head = i;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(int i =m+1; i<=r; i++) {
        sum = sum+arr[i];
        if(sum > right_sum) {
            right_sum = sum;
            tail = i;
        }
    }
    return(left_sum + right_sum);


}


int maxSubArraySum(int arr[],int l,int r)
{
    if(l==r) {
        return(arr[l]);
    }
    int m =(l+r)/2;

    int left = maxSubArraySum(arr,l,m);
    int right = maxSubArraySum(arr,m+1,r);
    int cross = maxCrossingSum(arr,l,m,r);
    return(left,right,cross);
}

int MaxSubArray_Recursive(int A[],int n)
{

    int sum = maxSubArraySum(A,0,n-1);
    printf("head = %d, tail =  %d\n",head,tail);
    return(sum);
}

