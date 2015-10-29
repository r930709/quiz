#include<stdio.h>
#include<stdlib.h>
#include "Linklist.h"


ListNode *Reversebetween_Iterative(ListNode *head,int m,int n)
{
    if(head==NULL || head->next == NULL || m ==n) {
        return(head);
    }

    int counter = 1;
    int retimes = (n-m+1);
    ListNode *cur =head, *sublist_prev = head, *prev = NULL, *next=NULL;

    while(counter < m) {
        cur = cur->next;
        counter++;
        if(counter < m) {
            sublist_prev = sublist_prev->next;
        }
    }

    prev = cur;
    while(counter <= n) {
        prev = prev->next;
        counter++;
    }
    while(retimes--) {
        next = cur->next ;
        cur->next = prev;

        prev= cur;
        cur =next;
    }
    if(m==1) {
        return(prev);
    }

    sublist_prev->next= prev;
    return(head);
}

