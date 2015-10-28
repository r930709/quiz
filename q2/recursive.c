#include<stdio.h>

int mystrlen(char str[])
{
    int count = 0;
    while(str[count]!='\0') {
        count++;
    }
    return(count);
}
char Small_Ch(char str[], char c,int head,int tail)
{

    int mid = (head+tail)/2;
    if(c == str[mid]) {
        while(c==str[++mid]);
        return(str[mid]);
    } else if(c > str[mid]) {
        if(c < str[mid+1]) {
            return(str[mid+1]);
        }
        Small_Ch(str,c,mid+1,tail);
    } else if(c < str[mid]) {
        Small_Ch(str,c,head,mid);
    }
}
char Smallest_Character_Recursive(char str[], char c)
{

    printf("%s\n",str);
    int tail = mystrlen(str);
    printf("%d\n",tail);
    int head = 0;
    if(c >= str[tail-1]) {

        return(str[0]);
    } else {

        return(Small_Ch(str,c,head,tail));
    }
}

