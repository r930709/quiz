#include<stdio.h>
#include<stdlib.h>
#include "Linklist.h"

ListNode *record[50];
int i=0;

ListNode *DetectCycle_Recursive(ListNode *head)
{
    ListNode *ptr = head;
    int j=0;

    if(ptr==NULL) {
        return(NULL);
    } else {
        record[i] = ptr;
        for(j=0; j<i; j++) {
            if(ptr==record[j]) {
                return(ptr);
            }
        }
        i++;
        ptr  = DetectCycle_Recursive(ptr->next);
        return(ptr);
    }
}

