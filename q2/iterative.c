#include<stdio.h>

int mystrlen(char str[])
{
    int count = 0;
    while(str[count]!='\0') {
        count++;
    }
    return(count);
}

char Smallest_Character_Iterative(char str[], char c)
{
    int i=0;
    if(c >= str[mystrlen(str)-1] || c < str[0]) {

        return(str[0]);
    } else {
        while(c >=str[i]) {
            i++;
        }
        return(str[i]);
    }
}

